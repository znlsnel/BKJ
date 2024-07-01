#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
        vector<int> dp(e + 1), answer;

        for (int i = 1; i <= e; i++)
        {
                for (int j = 1; j <= e; j++)
                {
                        if (i * j > e)
                                break;
                        dp[i * j]++;
                }
        }

        int maxId = e;
        int maxV = dp[e];
        for (int i = e; i >= 0; i--)
        {
                if (dp[i] >= maxV)
                {
                        maxId = i;
                        maxV = dp[i];
                }

                dp[i] = maxId;
        }

        for (int idx : starts)
                answer.push_back(dp[idx]);

        //  for (int n : dp)
            //  cout << n <<" ";

        return answer;
}

// arr[i][j] = 2 + arr[i/2][j/2];
// arr[i] = 
// 0 - 0
// 1 - 1
// 2 - 2
// 3 - 2
// 4 - 3
// 5 - 2
// 6 - 4


// 1 2 2 3 2 4

