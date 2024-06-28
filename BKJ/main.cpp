#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> orders; // 분배가능한 모든 경우의 수

// 모든 경우의 수를 구하는 함수(남은 인원, 유형, 컨테이너)
void backtracking(int remain, int idx, vector<int> order) {
        // 모든 인원을 담았으면 orders에 추가
        if (remain > 0)
        {
                for (int i = idx; i < order.size(); i++)
                {
                        order[i]++;
                        backtracking(remain - 1, i, order);
                        order[i]--;
                }
                return;
        }

        orders.push_back(order);
}

// 각 경우의 수에 맞춰 시뮬레이션을 돌림(순서,요청들)
int simulation(vector<int> order, vector<vector<int>> reqs)
{
        //  priority_queue<int> q[order.size()];
        priority_queue<int, vector<int>, greater<int>> q[order.size()];


        for (int i = 0; i < order.size(); i++)
        {
                while (order[i]--)
                        q[i].push(0);
        }

        int result = 0;
        for (auto req : reqs)
        {
                int start = req[0];
                int time = req[1];
                int type = req[2] - 1;

                int mento = q[type].top();
                q[type].pop();

                if (mento <= start)
                {
                        q[type].push(start + time);
                }
                else if (mento > start)
                {
                        q[type].push(mento + time);
                        result += mento - start;
                }
        }

        return result;
}
int solution(int k, int n, vector<vector<int>> reqs) {
        int answer = 99999999;

        vector<int> kind(k, 1);
        backtracking(n - k, 0, kind);

        for (auto order : orders) {
                answer = min(answer, simulation(order, reqs));
        }
        return answer;
}