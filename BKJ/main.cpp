#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define d 10000000
using namespace std;

int solution(string myString, string pat) {
        long long key = 0;

        std::transform(pat.begin(), pat.end(), pat.begin(), [](unsigned char c) {
                return std::tolower(c);
                });
        std::transform(myString.begin(), myString.end(), myString.begin(), [](unsigned char c) {
                return std::tolower(c);
                });

        int M = pat.size();
        int N = myString.size();
        int p = 0, k = 0;
        for (int i = 0; i < M; i++)
        {
                p += pat[i];
                k += myString[i];
        }

        int answer = 0;
        for (int i = 0; i < N - M + 1; i++)
        {
                if (p == k && pat == myString.substr(i, M))
                        answer++;

                k -= myString[i];
                k += myString[i + M];
        }

        return answer > 0 ? 1 : 0;
}