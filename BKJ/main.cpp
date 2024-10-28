#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
        if (n % 2 == 1)
                return 0;

        vector<long long> dp(n + 1);

        dp[0] = 1;
        dp[2] = 3;
        dp[4] = 11;

        for (int i = 6; i <= n; i += 2)
        {
                dp[i] = dp[i - 2] * 3;
                for (int j = i - 4; j >= 0; j -= 2)
                        dp[i] += dp[j] * 2;

                dp[i] %= 1000000007;
        }

        return dp[n];
}
// 연결 -> 4칸 -> 2개 * 
// 0 = 1;
// 2 = 3
// 4 = 11
// 6 = 33 6 2