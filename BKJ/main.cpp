#include <string>
#include <vector>
#include <iostream>

using namespace std;

int FindLastZero(string& s)
{
        for (int i = s.size() - 1; i >= 0; i--)
        {
                if (s[i] == '0')
                        return i;
        }
        return -1;
}

vector<string> solution(vector<string> s) {
        vector<string> answer;
        for (string& str : s)
        {
                int cnt = 0;
                string temp = "";

                for (int i = 0; i < str.size(); i++)
                {
                        temp += str[i];

                        int idx = temp.size() - 1;
                        if (idx >= 2 && temp.substr(idx - 2, 3) == "110") {
                                cnt++;
                                temp = temp.substr(0, idx - 2);
                        }
                }

                int idx = FindLastZero(temp);
                string ans;
                if (idx == -1)
                {
                        while (cnt--)
                                ans += "110";
                        ans += temp;
                }

                else
                {
                        for (int i = 0; i < temp.size(); i++)
                        {
                                ans += temp[i];
                                while (i == idx && cnt--)
                                        ans += "110";
                        }
                }
                answer.push_back(ans);
        }
        return answer;
}