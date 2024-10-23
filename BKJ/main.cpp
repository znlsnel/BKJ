#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int NEWNODE = 0;

// - 파악 방법
// 도넛
// 탐색을 시작한 노드에서 출발해서 다시 돌아오는 경우

// 막대
// 특정 노드에서 출발해서 끝 지점에 도달한 경우

// 8자 
//도넛과 마찬가지로 다시 돌아오는데 중간에 입구와 출구가 2개씩 있는 애 찾기

int CHECK(vector<vector<int>>& in, vector<vector<int>>& out, vector<bool>& visited, int idx)
{
        // NEW NODE를 제외한 모든 노드를 순회
        // 모든 노드의 간선의 수가 노드의 수가 
        // - 1    = 막대
        // 같다면  = 도넛
        // + 1    = 8자

        int nodeCnt = 0;
        int edgeCnt = 0;

        queue<int> q;
        q.push(idx);

        while (!q.empty())
        {
                nodeCnt++;
                int cur = q.front(); q.pop();
                visited[cur] = true;

                for (int next : out[cur])
                {
                        edgeCnt++;
                        if (visited[next] == false)
                                q.push(next);
                }
        }

        // 막대 끝부분이 들어온 경우 연결된 모든 노드에 체크를 해주어야함

        if (nodeCnt > edgeCnt)
        {
                int IDX = idx;
                q.push(IDX);

                while (!q.empty())
                {
                        int cur = q.front(); q.pop();
                        visited[cur] = true;
                        for (int next : in[cur])
                                q.push(next);
                }
        }


        // cout << idx << " : " << nodeCnt << ", " << edgeCnt << "\n";
        return nodeCnt == edgeCnt ? 1 : nodeCnt > edgeCnt ? 2 : 3;
}

vector<int> solution(vector<vector<int>> edges) {

        int size = 0;
        for (auto& edge : edges)
                size = max(size, max(edge[0], edge[1]));
        size++;

        vector<vector<int>> in(size);
        vector<vector<int>> out(size);

        for (auto& edge : edges)
        {
                out[edge[0]].push_back(edge[1]);
                in[edge[1]].push_back(edge[0]);

        }

        // 새롭게 추가된 정점 찾기
        for (int i = 1; i < size; i++) {
                if (out[i].size() >= in[i].size() + 2) {
                        NEWNODE = i;
                }
        }

        vector<int> answer(4);
        answer[0] = NEWNODE;

        vector<bool> visited(size);
        for (int i = 1; i < size; i++)
        {
                if (i == NEWNODE || in[i].size() + out[i].size() == 0 || visited[i])
                        continue;

                answer[CHECK(in, out, visited, i)]++;
        }

        return answer;
}

// 그래프의 형태 -> 도넛, 막대, 8자 모양
// 도넛 -> 일반 통행의 형태로 한바퀴를 돌게됨
// 막대 -> 일반 통행의 형태로 끝이 있음
// 8자 -> 도넛과 같이 한바퀴를 돌지만 입구, 출구가 2개인 애가 하나 있음

// 출력 -> 추가 생성된 정점 번호, 도넛 개수, 막대 개수, 8자 개수를 출력
// 핵심 -> 추가 생성된 정점이 뭔지 찾기, 정점 찾은 이후 그래프 파악하기

// - 파악 방법
// 도넛
// 탐색을 시작한 노드에서 출발해서 다시 돌아오는 경우

// 막대
// 특정 노드에서 출발해서 끝 지점에 도달한 경우

// 8자 
//도넛과 마찬가지로 다시 돌아오는데 중간에 입구와 출구가 2개씩 있는 애 찾기

// 추가 생성된 정점은 각 그래프와 연결되어 있음 
// 따라서 출구 - 입구가 2개 이상인 애가 추가 생성된 정점