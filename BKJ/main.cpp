#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N, M;

int answer = 10000000;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vector<vector<bool>> visited_red;
vector<vector<bool>> visited_blue;

void db(vector<vector<int>>& maze, int cnt)
{
        cout << "CNT : " << cnt << "\n";
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        bool r = visited_red[i][j];
                        bool b = visited_blue[i][j];
                        if (r && b)
                                cout << "[]" << " ";
                        else if (r)
                                cout << 1 << " ";
                        else if (b)
                                cout << 2 << " ";
                        else if (maze[i][j] >= 3)
                                cout << maze[i][j] << " ";

                        else
                                cout << 0 << " ";

                }
                cout << "\n";
        }
        cout << "\n";
}
bool check(vector<vector<int>>& maze, int y, int x)
{
        return y >= 0 && y < N && x >= 0 && x < M && maze[y][x] != 5;

        // 빨간색은 파란색으로 이동 가능
        // 파란색은 불가능
        // 파란색이 도착하지 않았다면 빨간색은 파란색으로 이돈 가능
        // 서로 자리를 바꾸는건 불가능

}


void DFS(vector<vector<int>>& maze, int y, int x, int oy, int ox, int cnt)
{
        // db(maze, cnt);                                                                                

        if (maze[y][x] == 3 && maze[oy][ox] == 4)
        {
                //  cout <<"도착\n";
                answer = min(answer, cnt);
                return;
        }

        // 빨간색은 파란색으로 이동 가능
        // 파란색은 불가능
        // 파란색이 도착하지 않았다면 빨간색은 파란색으로 이돈 가능
        // 서로 자리를 바꾸는건 불가능

        for (int i = 0; i < 4; i++)
        {
                int ny = y;
                int nx = x;
                if (maze[y][x] != 3)
                {
                        ny += dy[i];
                        nx += dx[i];
                }

                if (!check(maze, ny, nx) || (visited_red[ny][nx] && maze[y][x] != 3))
                        continue;

                visited_red[ny][nx] = true;

                for (int j = 0; j < 4; j++)
                {

                        int noy = oy;
                        int nox = ox;

                        if (maze[oy][ox] != 4)
                        {
                                noy += dy[j];
                                nox += dx[j];
                        }

                        if (!check(maze, noy, nox) || (visited_blue[noy][nox] && maze[oy][ox] != 4))
                                continue;

                        // 자리를 바꾸는 경우 
                        if (ny == oy && nx == ox && noy == y && nox == x)
                                continue;

                        // 같은 곳으로 가는 경우
                        if (ny == noy && nx == nox)
                                continue;

                        visited_blue[noy][nox] = true;
                        DFS(maze, ny, nx, noy, nox, cnt + 1);
                        //   cout << "반환\n";
                        visited_blue[noy][nox] = false;
                }
                visited_red[ny][nx] = false;
        }
}


int solution(vector<vector<int>> maze) {
        N = maze.size(); M = maze[0].size();

        visited_red.resize(N, vector<bool>(M, false));
        visited_blue.resize(N, vector<bool>(M, false));

        int ry, rx, by, bx;
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        if (maze[i][j] == 1)
                        {
                                ry = i;
                                rx = j;
                        }
                        else if (maze[i][j] == 2)
                        {
                                by = i;
                                bx = j;
                        }
                }
        }
        visited_red[ry][rx] = true;
        visited_blue[by][bx] = true;
        DFS(maze, ry, rx, by, bx, 0);

        return answer == 10000000 ? 0 : answer;
}