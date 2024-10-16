#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int Find(vector<int>& parents, int a)
{
        if (parents[a] == a)
                return a;

        return parents[a] = Find(parents, parents[a]);
}
void Union(vector<int>& parents, int a, int b)
{
        a = Find(parents, a);
        b = Find(parents, b);

        if (a < b)
                parents[b] = a;
        else
                parents[a] = b;
}


int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int BFS(vector<vector<int>>& land, vector<vector<bool>>& visited, vector<int>& parents, int y, int x)
{
        vector<pair<int, int>> pos;
        queue<pair<int, int>> q;

        q.push({ y, x });
        pos.push_back({ y, x });

        int cnt = 1;
        while (!q.empty())
        {
                auto& [cy, cx] = q.front(); q.pop();

                for (int i = 0; i < 4; i++)
                {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];

                        if (ny < 0 || ny >= land.size() || nx < 0 || nx >= land[0].size() ||
                                visited[ny][nx] || land[ny][nx] == 0)
                                continue;

                        visited[ny][nx] = true;
                        q.push({ ny, nx });
                        pos.push_back({ ny, nx });

                        int cidx = cy * land[0].size() + cx;
                        int nidx = ny * land[0].size() + nx;
                        Union(parents, cidx, nidx);

                        cnt++;
                }
        }

        for (auto& p : pos)
                land[p.first][p.second] = cnt;

        return cnt;
}

int solution(vector<vector<int>> land) {
        int answer = -11110;
        int size = land.size() * land[0].size();
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size()));

        vector<int> parents(size);
        for (int i = 0; i < size; i++)
                parents[i] = i;

        for (int i = 0; i < land.size(); i++)
        {
                for (int j = 0; j < land[i].size(); j++)
                {
                        if (visited[i][j] || land[i][j] == 0)
                                continue;
                        visited[i][j] = true;
                        BFS(land, visited, parents, i, j);
                }
        }

        for (int j = 0; j < land[0].size(); j++)
        {
                vector<bool> visit(size, false);
                int total = 0;
                for (int i = 0; i < land.size(); i++)
                {
                        int idx = i * land[0].size() + j;
                        int parent = Find(parents, idx);

                        if (visit[parent] == false)
                        {
                                total += land[i][j];
                                visit[parent] = true;
                        }
                }
                answer = max(answer, total);
        }

        return answer;
}