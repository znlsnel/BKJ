#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string convert(int n, int k)
{
        string ret;
        while (n > 0)
        {
                ret = to_string(n % k) + ret;
                n /= k;
        }
        return ret;
}

bool isPrime(long long num) {
        if (num < 2) return false;
        for (long long i = 2; i * i <= num; i++) {
                if (num % i == 0) return false;
        }
        return true;
}

bool isPrime(string num)
{
        long long ret = 0;
        for (int i = 0; i < num.size(); i++)
        {
                ret *= 10;
                ret += num[i] - '0';
        }

        return isPrime(ret);
}

int solution(int n, int k)
{
        vector<int> zeros;

        string number = convert(n, k);

        for (int i = 0; i < number.size(); i++)
                if (number[i] == '0')
                        zeros.push_back(i);

        int answer = 0;
        if (zeros.size() == 0 && isPrime(number))
                answer++;

        int prev = -1;
        for (int i = 0; i <= zeros.size(); i++)
        {
                if (zeros.size() == 0) {
                        break;
                }

                int idx = 0;
                if (i < zeros.size())
                        idx = zeros[i];
                string num = "";
                if (prev == -1)
                        num = number.substr(0, idx);

                else if (i == zeros.size() && zeros.size() > 0)
                        num = number.substr(prev + 1, number.size() - prev);

                else
                        num = number.substr(prev + 1, idx - (prev + 1));

                if (num != "" && isPrime(num))
                        answer++;

                prev = idx;
        }


        return answer;
}

// 소수 찾기~
// vector<int> ~ ~ ~ ~ ~ ~ ~

// n -> 소수 ? answer++;
// n 을 k진수로 변환 ( string 형식으로 보관 )
// 오른쪽에 0이 있는 경우
// 왼쪽에 0이 있는 경우
// 양쪽에 0이 있는 경우

// 0의 위치를 vector로 저장 (오름차순)
// [22] 0 [2] 0 [2] 0 0 [22] 0 [2] 0 [2] 0

// 오른쪽 먼저
// vector<int> 0모음 에서 index가 0 ~ N 까지 탐색 시작
// i를 탐색 할때 