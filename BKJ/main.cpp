#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> dp(1002, vector<int>(52, 10000000));
int answer = 1000000000;
int _tmpt, _t1, _t2, _a, _b;

void DFS(vector<int>& onboard, int idx, int curTmpt, int cost)
{

        if (idx >= onboard.size())
        {
                answer = min(answer, cost);
                return;
        }

        // 범위를 벗어나면 리턴
        if (onboard[idx] == 1 && (curTmpt < _t1 || curTmpt > _t2))
                return;

        // 이미 최적의 수를 찾았다면 리턴
        if (dp[idx][curTmpt] <= cost)
                return;


        dp[idx][curTmpt] = cost;

        // 끄는 경우
        DFS(onboard, idx + 1, min(_tmpt, curTmpt + 1), cost);
        // 온도 낮추는 경우
        DFS(onboard, idx + 1, curTmpt - 1, cost + _a);
        // 유지하는 경우
        DFS(onboard, idx + 1, curTmpt, cost + _b);

}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {

        _tmpt = temperature;
        _t1 = t1;
        _t2 = t2;
        _a = a;
        _b = b;

        if (_tmpt < _t1)
                _tmpt = t2 + (_t1 - _tmpt);

        DFS(onboard, 0, _tmpt, 0);

        return answer;
}

