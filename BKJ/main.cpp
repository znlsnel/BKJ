using System;

class Solution
{
        public int solution(int n, int a, int b)
        {
                int answer = 1;

                while (true)
                {
                        if (a % 2 == 0 && b + 1 == a)
                                break;
                        if (b % 2 == 0 && a + 1 == b)
                                break;

                        a = (a + 1) / 2;
                        b = (b + 1) / 2;

                        answer++;
                }

                return answer;
        }
}

// 1 2 3 4 5 6 7 8
// 1 2 3 4
// 1 2