#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {

        for (int i = 0; i < s.size(); i++)
        {
                if ((i == 0 || s[i - 1] == ' ') && (s[i] >= 'a' && s[i] <= 'z'))
                        s[i] = s[i] + ('A' - 'a');

                else if ((i > 0 && s[i - 1] != ' ') && s[i] >= 'A' && s[i] <= 'Z')
                        s[i] = s[i] - ('A' - 'a');
        }

        return s;
}