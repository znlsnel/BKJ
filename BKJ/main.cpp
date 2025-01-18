#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stack>

using namespace std;

bool check(string& str)
{
        stack<char> stk;
        for (char c : str)
        {
                if (c == '(' || c == '[' || c == '{')
                        stk.push(c);

                else
                {
                        // 스택이 비어 있거나 짝이 맞지 않으면 false
                        if (stk.empty())
                                return false;

                        char top = stk.top();
                        if ((c == ')' && top == '(') ||
                                (c == ']' && top == '[') ||
                                (c == '}' && top == '{'))
                        {
                                stk.pop(); // 짝이 맞으면 스택에서 제거
                        }

                        else
                                return false; // 짝이 맞지 않음
                }
        }

        // 모든 괄호가 짝지어져야 유효
        return stk.empty();
}

int solution(string s)
{
        int answer = 0;
        int cnt = s.size();

        while (cnt--)
        {
                if (check(s))
                        answer++;

                s = s.substr(1, s.size() - 1) + s[0];
        }


        return answer;
}