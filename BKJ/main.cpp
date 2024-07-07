#include <string>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1000000000;

struct compare
{
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
                if (a.first == b.first)
                        return a.second < b.second;
                return a.first > b.first;
        }
};

pair<int, int> ADD_PAIRS(pair<int, int>a, pair<int, int>b)
{
        pair<int, int> ret;
        ret.first = a.first + b.first;
        ret.second = a.second + b.second;
        return ret;
}


vector<pair<int, int>> dp;
int answer = -1;
int cnt = 0;
pair<int, int> DFS(int target)
{
        if (target == 0)
                return { 0, 0 };

        if (dp[target].first > 0)
                return dp[target];

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;



        // 트리플 +  60 이상의 큰 수
        if (target > 20)
        {
                int next = target - 60;
                if (next < 0)
                        next = target % 3;

                q.push(ADD_PAIRS(DFS(next), { 1, 0 }));
        }
        // 더블
        if (target > 20 && target <= 40)
                q.push(ADD_PAIRS(DFS(target % 2), { 1, 0 }));

        // 볼
        if (target >= 50)
                q.push(ADD_PAIRS(DFS(target - 50), { 1, 1 }));

        // 싱글
        int next = max(0, target - 20);
        q.push(ADD_PAIRS(DFS(next), { 1, 1 }));



        return dp[target] = q.top();
}

vector<int> solution(int target) {
        dp.resize(target + 1, { -1, -1 });
        DFS(target);
        return { dp[target].first, dp[target].second };
}

//dp[idx]
// 싱글, 더블, 트리플, 볼
//      


// 6까지는 트리플 x
// 10까지는 더블 x

// 1 ~ 20 // 싱글, 트리플 // 볼
// 가장 적은 다트로 목표 점수 채우기
// 싱글, 볼 맞춘 횟수 기록