#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
        deque<int> dq;
        int answer = 1000000000;

        for (int i = 0; i < stones.size(); i++) {
                // 새로운 요소 추가를 위해 덱의 뒤쪽에서 큰 값 제거
                while (!dq.empty() && stones[dq.back()] <= stones[i]) dq.pop_back();
                dq.push_back(i);

                // 덱의 앞쪽에서 윈도우에서 벗어난 값 제거
                if (dq.front() <= i - k) dq.pop_front();

                // 첫 번째 윈도우가 채워진 후부터 최소값 계산
                if (i >= k - 1) answer = min(answer, stones[dq.front()]);
        }

        return answer;
}