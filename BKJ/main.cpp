#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (auto& v : puddles) {
                int x = v[0] - 1;
                int y = v[1] - 1;
                dp[y][x] = -1;
        }

        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        if (dp[i][j] == -1)
                                continue;

                        int ny = i + 1;
                        int nx = j + 1;

                        if (nx < m && dp[i][nx] != -1)
                        {
                                dp[i][nx] += dp[i][j];
                                dp[i][nx] %= 1000000007;
                        }
                        if (ny < n && dp[ny][j] != -1)
                        {
                                dp[ny][j] += dp[i][j];
                                dp[i][nx] %= 1000000007;
                        }
                }
        }

        /* for (int i = 0; i < n; i++)
          {
              for (int j = 0; j < m; j++)
              {
                  cout << dp[i][j] << " ";
              }
              cout << "\n";
          }*/
        return dp[n - 1][m - 1];
}