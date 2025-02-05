#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // min 함수 사용

using namespace std;

const int INF = 1e9;  // 큰 값으로 설정

int solution(vector<string> strs, string t) {
        int n = t.length();
        vector<int> Dy(n + 1, INF);
        Dy[0] = 0;

        for (int i = 1; i <= n; i++)
        {
                for (const string& s : strs)
                {
                        int len = s.length();
                        int prev_idx = i - len;

                        if (prev_idx < 0)
                                continue;

                        bool is_match = true;
                        for (int j = 0; j < len; j++) {
                                if (t[prev_idx + j] != s[j]) {
                                        is_match = false;
                                        break;
                                }
                        }

                        if (is_match)
                                Dy[i] = min(Dy[i], Dy[prev_idx] + 1);
                }

        }

        return (Dy[n] == INF) ? -1 : Dy[n];  // 만들 수 없으면 -1 반환
}
