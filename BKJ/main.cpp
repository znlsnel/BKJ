#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

int Find(int b);
void UNION(int a, int b);

vector<int> parent;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void BFS(vector<vector<int>>& land, vector<vector<bool>>& visited, int i, int j)
{
        visited[i][j] = true;

        vector<pair<int, int>> v;
        queue<pair<int, int>> q;
        q.push({ i, j });
        v.push_back({ i, j });

        while (!q.empty())
        {
                auto [y, x] = q.front(); q.pop();

                UNION(i * land[0].size() + j, y * land[0].size() + x);

                for (int dir = 0; dir < 4; dir++)
                {
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];

                        // 시추 가능한 곳이 아니거나, 이미 시추한 곳이라면 continue;
                        if (ny < 0 || ny >= land.size() || nx < 0 || nx >= land[i].size()
                                || visited[ny][nx] || land[ny][nx] == 0)
                                continue;

                        q.push({ ny, nx });
                        v.push_back({ ny, nx });
                        visited[ny][nx] = true;
                }
        }

        for (auto& pos : v)
                land[pos.first][pos.second] = v.size();
}






int solution(vector<vector<int>> land)
{
        parent.resize(land.size() * land[0].size());
        for (int i = 0; i < parent.size(); i++)
                parent[i] = i;

        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size()));
        for (int i = 0; i < land.size(); i++)
        {
                for (int j = 0; j < land[i].size(); j++)
                        if (visited[i][j] == false && land[i][j] == 1)
                                BFS(land, visited, i, j);
        }


        int answer = 0;
        for (int j = 0; j < land[0].size(); j++)
        {
                set<int> visit;
                int size = 0;

                for (int i = 0; i < land.size(); i++)
                {
                        int idx = Find(i * land[0].size() + j);

                        // 석유가 없는 곳이거나, 이미 시추한 곳이면 패스
                        if (land[i][j] == 0 || visit.find(idx) != visit.end())
                                continue;

                        visit.insert(idx);
                        size += land[idx / land[0].size()][idx % land[0].size()];
                }

                answer = max(answer, size);
        }

        return answer;
}

void UNION(int a, int b)
{
        int A = Find(a);
        int B = Find(b);

        if (A <= B)
                parent[B] = A;
        else
                parent[A] = B;
}
int Find(int b)
{
        if (parent[b] == b)
                return b;

        return parent[b] = Find(parent[b]);
}
// BFS를 이용하여 석유 파악
// 하나의 덩어리에 속하는 모든 index에 석유 크기를 넣어줌
// 