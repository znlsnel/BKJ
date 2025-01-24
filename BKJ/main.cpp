public class Solution {

        int gcd(int a, int b)
        {
                if (b == 0)
                        return a;

                return gcd(b, a % b);
        }

        int lcm(int a, int b)
        {
                return a * b / gcd(a, b); // 절댓값 처리
        }

        public int solution(int[] arr) {

                int answer = 1;
                for (int i = 0; i < arr.Length; i++)
                        answer = lcm(answer, arr[i]);

                return answer;
        }
}