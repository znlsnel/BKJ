using System;

class Solution
{
        char[] itob(int num)
        {
                string str = "";
                while (num > 0)
                {
                        str = (num % 2) + str;
                        num /= 2;
                }

                char[] ret = new char[str.Length];
                for (int i = 0; i < str.Length; i++)
                        ret[i] = str[i];

                return ret;
        }

        int btoi(char[] num)
        {
                int ret = 0;

                for (int i = num.Length - 1; i >= 0; i--)
                {
                        ret *= 2;
                        ret += num[i] - '0';
                }
                return ret;
        }

        public int solution(int n)
        {
                int answer = 0;
                char[] bit = itob(n);

                int cnt = 0;
                for (int i = 0; i < bit.Length; i++)
                {
                        if (bit[i] == '1')
                                cnt++;
                }

                while (true)
                {
                        bit = itob(++n);
                        int cur = 0;
                        for (int i = 0; i < bit.Length; i++)
                                if (bit[i] == '1')
                                        cur++;

                        if (cur == cnt)
                                break;
                }


                return n;
        }
}