#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int _in[10000];
int _total[10000];

int ttoi(string str)
{
        int ret = 0;
        ret += (str[0] - '0') * 600;
        ret += (str[1] - '0') * 60;

        ret += (str[3] - '0') * 10;
        ret += str[4] - '0';
        return ret;
}

vector<string> split(string str)
{
        vector<string> ret;

        string temp;
        for (char c : str)
        {
                if (c == ' ') {
                        ret.push_back(temp);
                        temp = "";
                        continue;
                }
                temp.push_back(c);
        }
        ret.push_back(temp);
        return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
        set<int> numbers;

        for (string r : records)
        {
                vector<string> op = split(r);

                int time = ttoi(op[0]);
                int num = stoi(op[1]);
                numbers.insert(num);

                bool isIn = op[2] == "IN";

                if (isIn)
                {
                        _in[num] = time;
                }
                else
                {
                        _total[num] += time - _in[num];
                        _in[num] = -1;
                }
        }
        vector<int> number;
        for (int n : numbers)
                number.push_back(n);
        sort(number.begin(), number.end());

        int maxT = 59 + (3 * 60) + (2 * 600);
        vector<int> answer;

        for (int num : number)
        {
                if (_in[num] >= 0)
                {
                        _total[num] += maxT - _in[num];
                }

                if (_total[num] > 0)
                {
                        if (fees[0] >= _total[num])
                        {
                                answer.push_back(fees[1]);
                        }
                        else
                        {
                                int overtime = _total[num] - fees[0];
                                int cntTime = 1;

                                while (overtime > fees[2])
                                {
                                        overtime -= fees[2];
                                        cntTime++;
                                }


                                answer.push_back(fees[1] + (cntTime * fees[3]));

                        }
                }

        }



        return answer;
}