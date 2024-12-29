#include <string>
#include <vector>

using namespace std;

int ttoi(string time, bool isEnd = false)
{
        int ret = isEnd ? 9 : 0;
        ret += time[4] - '0';
        ret += (time[3] - '0') * 10;
        ret += (time[1] - '0') * 60;
        ret += (time[0] - '0') * 600;
        return ret;
}

int solution(vector<vector<string>> book_time) {
        int answer = 0;
        vector<int> dp(9999);

        for (auto& book : book_time)
        {
                int start = ttoi(book[0]);
                int end = ttoi(book[1], true);

                dp[start]++;
                dp[end + 1]--;

                // while (start <= end)
                // {
                //     dp[start]++;
              //       answer = max(answer, dp[start]);
               //      start++;
               //  }
        }
        answer = dp[0];
        for (int i = 1; i < 9999; i++) {
                dp[i] = dp[i] + dp[i - 1];
                answer = max(answer, dp[i]);
        }


        return answer;
}
