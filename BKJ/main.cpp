#include <string>
#include <vector>
using namespace std;

long long solution(int k, int d)
{
        long long length = (long long)d * d;
        long long answer = d / k + 1;

        for (long long y = 0; y < d; y += k)
        {
                int start = 1, end = d, ret = 0;
                while (start <= end)
                {
                        long long x = (start + end) / 2;
                        if (x * x + y * y <= length) {
                                start = x + 1;
                                ret = x;
                        }
                        else
                                end = x - 1;
                }
                answer += ret / k;
        }

        return answer;
}