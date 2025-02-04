public class Solution {
        public int LengthOfLIS(int[] nums)
        {
                int n = nums.Length;
                int[] dp = new int[n];
                Array.Fill(dp, 1); // 최소 길이는 1 (각 원소 자체만 고려)

                int maxLen = 1;

                for (int i = 0; i < n; i++)
                {
                        for (int j = i + 1; j < n; j++)
                        {
                                if (nums[j] > nums[i]) {
                                        dp[j] = Math.Max(dp[j], dp[i] + 1);
                                        maxLen = Math.Max(maxLen, dp[j]);
                                }
                        }
                }

                return maxLen;
        }
}