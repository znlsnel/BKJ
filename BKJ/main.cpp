#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {

        int minNum = 1000000000;
        int maxNum = -1000000000;

        int num = 0;
        bool isMinus = 0;
        for (int i = 0; i <= s.size(); i++)
        {
                if (i == s.size() || s[i] == ' ') {
                        if (isMinus) {
                                num *= -1;
                        }
                        minNum = min(minNum, num);
                        maxNum = max(maxNum, num);

                        num = 0;
                        isMinus = false;
                        continue;
                }

                if (s[i] == '-')
                        isMinus = true;
                else
                        num = num * 10 + (s[i] - '0');
        }

        return to_string(minNum) + " " + to_string(maxNum);
}