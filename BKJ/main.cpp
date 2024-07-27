#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
        fill(&dp[0][0], &dp[500][500], -1);
        int n = triangle.size();

        for (int i = 0; i < triangle.size(); i++)
                dp[n - 1][i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--)
        {
                for (int j = 0; j <= i; j++)
                {
                        dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
                }
        }
        return dp[0][0];
}