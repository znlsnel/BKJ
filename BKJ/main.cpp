using System;

public class Solution
{
        int Function(int openCnt, int n)
        {
                if (openCnt < 0)
                        return 0;

                if (n == 0)
                        return openCnt == 0 ? 1 : 0;

                int ret = Function(openCnt + 1, n - 1);
                ret += Function(openCnt - 1, n - 1);

                return ret;
        }

        public int solution(int n)
        {
                int answer = 0;
                return Function(0, n * 2);
        }
}