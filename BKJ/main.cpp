#include <string>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;
const int INF = 200000000;

vector<vector<int>> dp;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

        dp.resize(n + 1, vector<int>(n + 1, INF));

        for (auto fare : fares)
        {
                int A = fare[0];
                int B = fare[1];
                int cost = fare[2];

                dp[A][B] = cost;
                dp[B][A] = cost;
        }

        for (int i = 1; i <= n; i++)
                dp[i][i] = 0;

        for (int k = 1; k <= n; k++)
        {
                for (int i = 1; i <= n; i++)
                {
                        for (int j = 1; j <= n; j++)
                        {
                                if (dp[i][k] < INF && dp[k][j] < INF) {
                                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                                }
                        }
                }
        }


        int answer = INF;
        for (int i = 1; i <= n; ++i) {
                answer = min(answer, dp[s][i] + dp[i][a] + dp[i][b]);

        }



        return answer;
}