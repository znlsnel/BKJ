#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ConvertDateToInt(string str, int& termID)
{
        int result = 0;
        int p = 0;
        for (int i = str.size() - 1; i >= 0; i--)
        {
                if (str[i] >= 'A' && str[i] <= 'Z')
                {
                        termID = str[i] - 'A';
                        continue;
                }

                if (str[i] == '.' || str[i] == ' ')
                        continue;

                result += int(str[i] - '0') * pow(10, p++);
        }

        return result;
}

static int _terms[26];
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {

        for (string s : terms)
        {
                int id = s[0] - 'A';
                int p = 0;
                for (int i = s.size() - 1; i > 0; i--)
                {
                        if (s[i] == ' ')
                                break;

                        _terms[id] += int(s[i] - '0') * pow(10, p++);
                }
        }

        int dummy;
        int TODAY = ConvertDateToInt(today, dummy);

        vector<int> answer;
        for (int i = 0; i < privacies.size(); i++)
        {
                int term;
                int privacie = ConvertDateToInt(privacies[i], term);
                term = _terms[term];

                int year = privacie / 10000;
                int month = ((privacie % 10000) / 100) + term;
                int day = privacie % 100;

                day--;
                if (day == 0)
                {
                        day = 28;
                        month--;
                }

                while (month > 12)
                {
                        month -= 12;
                        year++;
                }

                int result = (year * 10000) + (month * 100) + day;


                if (result < TODAY)
                        answer.push_back(i + 1);


        }

        return answer;
}