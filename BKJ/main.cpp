#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> orders;
void backtracking(vector<int> mentos, int idx, int coin)
{
        if (coin == 0) {
                orders.push_back(mentos);
                return;
        }

        for (int i = idx; i < mentos.size(); i++)
        {
                mentos[i]++;
                backtracking(mentos, i, coin - 1);
                mentos[i]--;
        }
}

int Counseling(vector<int>& order, vector<vector<int>>& reqs)
{
        priority_queue<int, vector<int>, greater<int>> q[order.size()];

        for (int i = 0; i < order.size(); i++)
        {
                while (order[i]-- > 0)
                        q[i].push(0);

        }



        int ret = 0;
        for (vector<int>& req : reqs)
        {
                int start = req[0];
                int time = req[1];
                int type = req[2] - 1;

                int mento = q[type].top(); q[type].pop();

                if (mento > start)
                {
                        ret += mento - start;
                        q[type].push(mento + time);
                }
                else if (mento <= start)
                {
                        q[type].push(start + time);
                }
        }



        return ret;
}

int solution(int k, int n, vector<vector<int>> reqs) {
        vector<int> mentos(k, 1);
        backtracking(mentos, 0, n - k);


        int answer = Counseling(orders[0], reqs);
        for (int i = 1; i < orders.size(); i++)
                answer = min(answer, Counseling(orders[i], reqs));

        return answer;
}