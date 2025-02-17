using System;

public class Solution {
        public int solution(int n, int count) {
                long answer = 0;
                long[, ] dp = new long[n + 1, n + 1]; // dp[n, count]
                dp[1, 1] = 1;

                for (int i = 2; i <= n; i++)
                {
                        for (int j = 1; j <= i; j++)
                        {
                                dp[i, j] = (dp[i - 1, j] * (i - 1) * 2 + dp[i - 1, j - 1]) % 1000000007;
                        }
                }

                answer = dp[n, count];

                return (int)answer;
        }
}