#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
        int n = matrix_sizes.size();
        int INT_MAX = 1000000000;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // dp[i][j] = i ~ j까지의 최소 곱셈 횟수
        for (int length = 1; length < n; length++)
        {
                for (int i = 0; i + length < n; i++)
                {
                        int j = i + length;
                        dp[i][j] = INT_MAX;

                        // i ~ j 사이를 분할하기 위해 k를 넣음
                        for (int k = i; k < j; k++)
                        {
                                // 행렬 i ~ k + k+1 ~ j 까지의 합 
                                int cost = dp[i][k] + dp[k + 1][j] +
                                        matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1];
                                cout << "DP[" << i << "][" << k << "] == " << dp[i][k] << ", DP[" << k + 1 << "][" << j << "] == " << dp[k + 1][j] << "\n";

                                cout << "COST : ";
                                cout << matrix_sizes[i][0] << " * " << matrix_sizes[k][1] << " * " << matrix_sizes[j][1] << "\n";

                                dp[i][j] = min(dp[i][j], cost);
                                cout << "DP[" << i << "][" << j << "] = " << dp[i][j] << "\n";
                                cout << "\n";
                        }
                }
        }

        return dp[0][n - 1];
}