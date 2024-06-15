#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ttoi(string time)
{
        int ret = 0;

        ret += time[7] - '0';      // 1초
        ret += (time[6] - '0') * 10; // 10초

        ret += (time[4] - '0') * 60; // 1분
        ret += (time[3] - '0') * 600; // 10분

        ret += (time[1] - '0') * 3600; // 1시간
        ret += (time[0] - '0') * 36000; // 10시간

        return ret;
}

string itot(int time)
{
        string ret;

        ret += to_string(time / 36000);
        time %= 36000;

        ret += to_string(time / 3600);
        time %= 3600;

        ret += ":";

        ret += to_string(time / 600);
        time %= 600;

        ret += to_string(time / 60);
        time %= 60;

        ret += ":";

        ret += to_string(time / 10);
        time %= 10;

        ret += to_string(time);

        return ret;
}

vector<string> splite(string str)
{
        vector<string> ret;
        string s;
        for (auto c : str)
        {

                if (c == '-')
                {
                        ret.push_back(s);
                        s = "";
                        continue;
                }
                s += c;
        }
        ret.push_back(s);
        return ret;
}
long dp[360000];

string solution(string play_time, string adv_time, vector<string> logs) {
        string answer = "";

        int play_length = ttoi(play_time);
        int adv_length = ttoi(adv_time);

        for (string l : logs)
        {
                vector<string> log = splite(l);
                int start = ttoi(log[0]);
                int end = ttoi(log[1]);

                dp[start]++;
                dp[end]--;
        }

        for (int i = 1; i <= play_length; i++)
                dp[i] += dp[i - 1];

        long long temp = 0;
        long long max = 0;
        long index = 0;

        for (int i = 0; i < play_length; i++)
        {
                if (i < adv_length)
                {
                        temp += dp[i];
                        max = temp;
                }
                else
                {
                        temp -= dp[i - adv_length];
                        temp += dp[i];


                        if (temp > max)
                        {
                                max = temp;
                                index = i - adv_length + 1;
                        }
                }


        }




        return itot(index);
}