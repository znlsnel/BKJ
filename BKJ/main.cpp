#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int ttoi(string s)
{
        int ret = 0;

        ret += (s[4] - '0');
        ret += (s[3] - '0') * 10;

        ret += (s[1] - '0') * 60;
        ret += (s[0] - '0') * 600;

        return ret;
}

string itot(int time)
{
        string ret = "";
        ret += to_string(time / 600);
        ret += to_string(time % 600 / 60);
        ret += ':';
        ret += to_string(time % 600 % 60 / 10);
        ret += to_string(time % 600 % 60 % 10);

        return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {

        vector<int> times;

        for (string& t : timetable)
                times.push_back(ttoi(t));

        sort(times.begin(), times.end());

        int curBus = ttoi("09:00");
        int lastBus = curBus + (n - 1) * t;

        int idx = 0, seatsLeft = m;

        while (curBus <= lastBus)
        {
                if (seatsLeft > 0 && idx < times.size() && times[idx] <= curBus)
                {
                        seatsLeft--;
                        cout << "한명 앉음 idx : " << idx << "\n";
                        idx++;

                }
                else
                {
                        if (curBus == lastBus)
                                break;

                        cout << "다음 버스요~ " << "\n";
                        curBus += t;
                        seatsLeft = m;

                }
        }
        if (idx > times.size() - 1)
                idx = times.size() - 1;

        // 현재 버스가 마지막 버스일 때    
        if (curBus == lastBus)
        {
                // 남은 자리가 있다면 버스 시간에
                if (seatsLeft > 0)
                        return itot(lastBus);

                // 자리가 없다면
                else
                        return itot(times[idx] - 1);
        }
        else
                return itot(lastBus);

}