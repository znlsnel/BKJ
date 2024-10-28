#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int BFS(vector<vector<int>>& picture, vector<vector<bool>>& visited, int y, int x)
{
        int size = 1;

        int color = picture[y][x];
        visited[y][x] = true;
        queue<pair<int, int>> q;
        q.push({ y, x });


        while (!q.empty())
        {
                auto [cy, cx] = q.front(); q.pop();

                for (int i = 0; i < 4; i++)
                {
                        auto [ny, nx] = make_pair(cy + dy[i], cx + dx[i]);

                        if (ny < 0 || ny >= picture.size() ||
                                nx < 0 || nx >= picture[0].size() ||
                                picture[ny][nx] == 0 || picture[ny][nx] != color || visited[ny][nx])
                                continue;

                        visited[ny][nx] = true;
                        q.push({ ny, nx });
                        size++;
                }
        }

        return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

        vector<int> answer(2);

        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        if (visited[i][j] || picture[i][j] == 0)
                                continue;

                        int ret = BFS(picture, visited, i, j);
                        if (ret > 0) {
                                answer[0]++;
                                answer[1] = max(answer[1], ret);
                        }
                }
        }

        return answer;
}

// 1 1 1 0 
// 1 1 1 0
// 0 0 0 1
// 0 0 0 1
// 0 0 0 1
// 0 0 0 1