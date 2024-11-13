#include <string>
#include <iostream>

using namespace std;

int solution(string s) {

        if (s.size() == 1)
                return 1;

        int answer = 99999999;

        for (int len = 1; len <= s.size() / 2; len++)
        {
                string str = s.substr(0, len);
                string tmp = "";
                int cnt = 1;

                int idx = 0;
                for (int i = len; i < s.size(); i += len)
                {
                        idx = i;
                        string nxt = s.substr(i, len);

                        if (str == nxt)
                                cnt++;

                        else
                        {
                                tmp = cnt > 1 ? tmp + to_string(cnt) + str : tmp + str;
                                cnt = 1;
                                str = nxt;
                        }
                }

                str = s.substr(idx, len);
                tmp = cnt > 1 ? tmp + to_string(cnt) + str : tmp + str;

                answer = min(answer, int(tmp.size()));
        }

        return answer;
}