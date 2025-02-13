public class Solution {
        public long solution(int n) {
                int MOD = 1234567;
                int[] count = new int[n + 1];
                count[0] = 1;
                count[1] = 1;


                for (int i = 2; i <= n; i++)
                        count[i] = (count[i - 1] + count[i - 2]) % MOD;

                return count[n];
        }
}
