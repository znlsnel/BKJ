#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int BFS(vector<string>& maps, vector<vector<bool>>& visited, int y, int x)
{
        int ret = 0;

        queue<pair<int, int>> q;
        visited[y][x] = true;
        q.push({ y, x });

        while (!q.empty())
        {
                auto [cy, cx] = q.front(); q.pop();
                ret += maps[cy][cx] - '0';

                for (int i = 0; i < 4; i++)
                {
                        auto [ny, nx] = make_pair(cy + dy[i], cx + dx[i]);
                        if (ny < 0 || ny >= visited.size() || nx < 0 || nx >= visited[ny].size()
                                || visited[ny][nx] || maps[ny][nx] == 'X')
                                continue;

                        visited[ny][nx] = true;
                        q.push({ ny, nx });
                }

        }


        return ret;

}

vector<int> solution(vector<string> maps) {
        vector<int> answer;
        vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size()));

        for (int i = 0; i < maps.size(); i++)
        {
                for (int j = 0; j < maps[i].size(); j++)
                {
                        if (visited[i][j] || maps[i][j] == 'X')
                                continue;

                        answer.push_back(BFS(maps, visited, i, j));
                }
        }

        sort(answer.begin(), answer.end());
        if (answer.size() == 0)
                answer.push_back(-1);
        return answer;
}