#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

bool visited[500][500][4];
using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int N, M;
int GetDir(char c, int Dir)
{
        if (c == 'S')
                return Dir;

        else if (c == 'L')
        {
                if (Dir == 0) return 2;
                if (Dir == 1) return 3;
                if (Dir == 2) return 1;
                if (Dir == 3) return 0;
        }
        if (Dir == 0) return 3;
        if (Dir == 1) return 2;
        if (Dir == 2) return 0;
        return 1;
}

int Simulation(vector<string>& grid, int y, int x, int dir, int len = 0)
{
        if (visited[y][x][dir])
                return len;

        visited[y][x][dir] = true;

        auto [nx, ny, nd] = make_tuple(x, y, GetDir(grid[y][x], dir));
        nx += dx[nd];
        ny += dy[nd];
        if (nx < 0) nx = M - 1;
        if (ny < 0) ny = N - 1;
        if (nx == M) nx = 0;
        if (ny == N) ny = 0;

        return Simulation(grid, ny, nx, nd, len + 1);
}

vector<int> solution(vector<string> grid) {
        vector<int> answer;
        N = grid.size();
        M = grid[0].size();
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        for (int dir = 0; dir < 4; dir++)
                        {
                                int ret = Simulation(grid, i, j, dir, 0);
                                if (ret > 0) answer.push_back(ret);
                        }

                }
        }
        sort(answer.begin(), answer.end());
        return answer;
}