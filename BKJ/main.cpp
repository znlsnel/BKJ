#include <string>
#include <vector>
#define INF 10001

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {

        int dp[151][151];
        fill(&dp[0][0], &dp[150][150], INF);

        int goal_alp = 0;
        int goal_cop = 0;
        for (auto p : problems)
        {
                goal_alp = max(p[0], goal_alp);
                goal_cop = max(p[1], goal_cop);
        }
        alp = min(alp, goal_alp);
        cop = min(cop, goal_cop);

        dp[alp][cop] = 0;
        for (int i = alp; i <= goal_alp; i++)
        {
                for (int j = cop; j <= goal_cop; j++)
                {
                        if (i < goal_alp)
                                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                        if (j < goal_cop)
                                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

                        for (auto p : problems)
                        {
                                if (i >= p[0] && j >= p[1])
                                {
                                        int nextAlp = min(i + p[2], goal_alp);
                                        int nextCop = min(j + p[3], goal_cop);
                                        dp[nextAlp][nextCop] = min(dp[nextAlp][nextCop], dp[i][j] + p[4]);
                                }
                        }
                }
        }


        return dp[goal_alp][goal_cop];
}