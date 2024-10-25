#include <string>
#include <vector>
#include <iostream>

using namespace std;
int ttoi(string time)
{
        int ret = 0;
        ret += time[4] - '0';
        ret += (time[3] - '0') * 10;
        ret += (time[1] - '0') * 60;
        ret += (time[0] - '0') * 600;

        return ret;
}

string itot(int time)
{
        string ret;
        ret = to_string(time / 600);
        ret += to_string((time % 600) / 60);
        ret += ':';
        ret += to_string((time % 600 % 60) / 10);
        ret += to_string(time % 600 % 60 % 10);

        return ret;

}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

        int start_op = ttoi(op_start);
        int end_op = ttoi(op_end);

        int time = ttoi(pos);
        time = time >= start_op && time < end_op ? end_op : time;
        int videoSize = ttoi(video_len);

        for (string& command : commands)
        {
                if (command == "next")
                        time = min(time + 10, videoSize);
                else if (command == "prev")
                        time = max(time - 10, 0);

                if (time >= start_op && time <= end_op)
                        time = end_op;
        }

        return itot(time);
}