#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> lights;
vector<bool> isLighting;
int answer = 0;

void DFS(int idx, int parent)
{
        for (int& n : lights[idx])
        {
                if (n != parent)
                {
                        DFS(n, idx);

                        if (!isLighting[idx] && !isLighting[n]) {
                                isLighting[idx] = true;
                                answer++;
                        }
                }
        }
}

int solution(int n, vector<vector<int>> lighthouse) {
        lights.resize(n + 1);
        isLighting.resize(n + 1);
        for (auto& l : lighthouse)
        {
                int a = l[0];
                int b = l[1];
                lights[a].push_back(b);
                lights[b].push_back(a);
        }
        DFS(1, 0);
        return answer;
}

// 1 - 2 3 4 5
// 2 - 1 9
// 3 - 1
// 4 - 1
// 5 - 1 6
// 6 - 5 7 8
// 7 - 6
// 8 - 6
// 9 - 2 10
// 10 - 9

// 조건 1. 2개 이상의 노드와 연결된 애들
// 조건 2. 옆에 켜져있는 등대가 있으면 안됨

// 
// priority_queue<연결된 노드 수, index> q;
// vector<bool> visited;
// if (q.top이 등대로 선정된 노드와 연결 되어 있다면)
//      return;
// 아니면 등대로 지정
// 핵심은 등대로 선정된 노드와 연결 되어 있는지 어떻게 확인하는가?
// 
// 