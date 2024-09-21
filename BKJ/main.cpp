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

        // 마지막 버스까지 계속 처리
        for (int i = 0; i < n; ++i) {
                int seatsLeft = m;

                while (seatsLeft > 0 && idx < times.size() && times[idx] <= curBus) {
                        seatsLeft--;
                        idx++;
                }

                // 마지막 버스일 때
                if (i == n - 1)
                {
                        // 자리가 남으면 마지막 버스 시간에 탑승 가능
                        if (seatsLeft > 0)
                        {
                                return itot(curBus);
                        }

                        // 자리가 없으면 마지막으로 탄 사람보다 1분 빨리
                        else
                        {
                                return itot(times[idx - 1] - 1);
                        }
                }

                curBus += t;  // 다음 버스 시간으로 갱신
        }

        return itot(lastBus);

}