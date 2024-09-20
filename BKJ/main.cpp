#include <iostream>
#include <string>
using namespace std;

int palindrome(string& s, int left, int right)
{
        while (left >= 0 && right < s.size())
        {
                if (s[left] != s[right])
                        break;

                left--;
                right++;
        }

        return right - left - 1;
}

int solution(string s)
{
        int answer = 0;
        for (int i = 0; i < s.size(); i++)
        {
                int a = palindrome(s, i, i);
                int b = palindrome(s, i - 1, i);
                answer = max(answer, max(a, b));
        }

        return answer;
}