#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money)
{
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        // 1, 2, 5
        for (int coin : money)
        {
                for (int i = coin; i <= n; ++i)
                {
                        cout << i << " += " << dp[i - coin] << "(" << i - coin << ")\n";
                        dp[i] += dp[i - coin];
                }
        }


        return dp[n] % 1000000007;
}