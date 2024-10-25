#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {

        int start = 1;
        int end = *max_element(diffs.begin(), diffs.end());
        int answer = end;

        while (start <= end)
        {
                int level = (start + end) / 2;
                long long time = times[0] * max(diffs[0] - level, 0) + times[0];
                for (int i = 1; i < times.size(); i++)
                        time += (times[i - 1] + times[i]) * max(diffs[i] - level, 0) + times[i];

                if (time <= limit) {
                        end = level - 1;
                        answer = min(answer, level);
                }
                else
                        start = level + 1;
        }
        return answer;
}

// 제한 시간 내에 문제를 모두 풀기 위한 최소 레벨
// 2 4 7