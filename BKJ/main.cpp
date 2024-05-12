#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static long dp[100001][5][5];
int mp[5][5] =
{
        {0, 2, 2, 2, 2},
        {2, 1, 3, 4, 3},
        {2, 3, 1, 3, 4},
        {2, 4, 3, 1, 3},
        {2, 3, 4, 3, 1},
};

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);


        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                        for (int k = 0; k < 100001; k++) {
                                dp[k][i][j] = 1000000;
                        }
                }
        }

        dp[0][0][0] = 0;
        vector<int> moves;
        int n;
        while (true) {
                cin >> n;
                if (n == 0) break;
                moves.push_back(n);
        }

        int s = 1;
        for (int n : moves) {
                for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {

                                if (n == 0)
                                        break;

                                if (n != j) // 왼발
                                        dp[s][n][j] = min(dp[s][n][j], dp[s - 1][i][j] + mp[i][n]);

                                if (n != i) // 오른발
                                        dp[s][i][n] = min(dp[s][i][n], dp[s - 1][i][j] + mp[j][n]);
                        }
                }
                s++;
        }

        long minVal = 1000000;
        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                        minVal = min(minVal, dp[s - 1][i][j]);
                }
        }

        cout << minVal << "\n";
}



