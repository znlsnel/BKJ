#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
        int s = 0, e = 0;
        int sum = sequence[0]; // 부분 수열의 합
        int subLen = sequence.size() + 1; // 부분 수열의 길이
        pair<int, int> result; // 부분 수열의 시작 인덱스와 마지막 인덱스를 담은 객체

        while (s <= e && e < sequence.size())
        {
                if (sum < k)
                        sum += sequence[++e];

                else if (sum == k)
                {
                        if (e - s + 1 < subLen)
                        { // 길이가 더 짧은 수열이면
                                subLen = e - s + 1;
                                result = { s, e };
                        }

                        else if (e - s + 1 == subLen)
                        {
                                if (s < result.first)
                                { // 시작 인덱스가 더 작으면
                                        result = { s, e };
                                }
                        }

                        sum -= sequence[s++];
                }

                else sum -= sequence[s++];
        }

        return { result.first, result.second };
}