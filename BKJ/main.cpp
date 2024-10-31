#include <string>
#include <vector>

using namespace std;

int CheckPrime(long long num)
{
        int result = 1;
        for (int i = 2; i * i <= num; i++)
        {
                if (num % i == 0) {
                        if (num / i <= 10000000)
                                return num / i;

                        result = i;
                }

        }
        return num == 1 ? 0 : result;
}

vector<int> solution(long long begin, long long end) {
        vector<int> answer;

        for (long long i = begin; i <= end; i++)
                answer.push_back(CheckPrime(i));

        return answer;
}