#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isProper(string s) // "올바른 괄호 문자열"인지 판별
{
        int openCnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
                if (s[i] == '(')
                        openCnt++;

                if (s[i] == ')')
                        openCnt--;

                if (openCnt < 0)
                        return false;
        }

        return openCnt == 0;
}

string removeAndReverse(string u)  // 4-4 의 과정
{
        u = u.substr(1, u.size() - 2);

        for (char& c : u) // 괄호 방향 뒤집기
                c = c == ')' ? '(' : ')';

        return u;
}

string convert(string w)
{
        if (w == "") return w;  // 1. 빈 문자열인 경우 검사

        int openCount = 0; int closeCount = 0;
        int index = 0;
        for (int i = 0; i < w.length(); i++)
        {
                if (w[i] == '(') openCount++;
                if (w[i] == ')') closeCount++;

                if (openCount == closeCount)
                {
                        index = i + 1;
                        break;
                }
        }

        string u = w.substr(0, index);
        string v = w.substr(index);

        string result = "";
        if (isProper(u))
                result = u + convert(v);
        else
                result = "(" + convert(v) + ")" + removeAndReverse(u);

        return result;
}

string solution(string p) {
        string answer = convert(p);
        return answer;
}