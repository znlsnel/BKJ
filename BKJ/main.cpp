#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool road[51][51];
int answer = 1000000000;
int iy, ix;

bool isInSide(vector<int>& r, float pnt_y, float pnt_x)
{
        bool isInside = pnt_x > r[0] && pnt_x < r[2] && pnt_y > r[1] && pnt_y < r[3];
        return isInside;
}

bool isOutSide(vector<int>& r, float pnt_y, float pnt_x)
{
        bool isOutSide = pnt_x < r[0] || pnt_x > r[2] || pnt_y < r[1] || pnt_y > r[3];
        return isOutSide;
}




bool Check(int y, int x)
{
        return y >= 0 && y < 51 && x >= 0 && x < 51 && road[y][x];
}


void DFS(vector<vector<int>>& rectangle, int y, int x, int cost)
{
        //cout << "Y, X : "<<y << ", " << x << "  COST :" << cost << "\n";

        for (auto& r : rectangle)
        {
                if (isInSide(r, y, x))
                {
                        road[y][x] = false;
                        return;
                }

        }



        if (y == iy && x == ix)
        {
                answer = min(answer, cost);
                return;
        }

        road[y][x] = false;

        for (int i = 0; i < 4; i++)
        {
                int ny = y + dy[i];
                int nx = x + dx[i];

                bool movable = true;
                bool allout = true;
                for (auto& r : rectangle)
                {
                        if (isInSide(r, float(ny + y) / 2.0f, float(nx + x) / 2.0f))
                        {
                                movable = false;
                                break;
                        }

                        if (isOutSide(r, float(ny + y) / 2.0f, float(nx + x) / 2.0f) == false)
                        {
                                allout = false;
                        }
                }

                if (!allout && movable && Check(ny, nx))
                {
                        DFS(rectangle, ny, nx, cost + 1);
                }
        }

        road[y][x] = true;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

        iy = itemY;
        ix = itemX;
        for (auto& r : rectangle)
        {
                int x1, y1, x2, y2;
                x1 = r[0];
                y1 = r[1];
                x2 = r[2];
                y2 = r[3];

                for (int i = y1; i <= y2; i++)
                {
                        road[i][x1] = true;
                        road[i][x2] = true;
                }

                for (int i = x1; i <= x2; i++)
                {
                        road[y1][i] = true;
                        road[y2][i] = true;
                }
        }

        if (false)
        {
                for (int i = 50; i >= 0; i--)
                {
                        for (int j = 0; j < 51; j++)
                        {
                                if (road[i][j] == true)
                                {
                                        cout << "1 ";
                                }
                                else
                                        cout << "  ";
                        }
                        cout << "\n";
                }
        }


        DFS(rectangle, characterY, characterX, 0);
        return answer;
}


// 선 으로 정라하기
// 내 이동방향 -> 가로지르는 선이 있으면 그 선으로 가라타기
// 두 방향으로 DFS