#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

vector<vector<int>> costs;


void DFS(vector<string>& board, int y, int x, int cost)
{
        if (costs[y][x] <= cost)
                return;
        costs[y][x] = cost;

        for (int i = 0; i < 4; i++)
        {
                int ny = y;
                int nx = x;

                while (ny + dy[i] < board.size() && ny + dy[i] >= 0 &&
                        nx + dx[i] < board[0].size() && nx + dx[i] >= 0 &&
                        board[ny + dy[i]][nx + dx[i]] != 'D')
                {
                        ny += dy[i];
                        nx += dx[i];
                }

                if (ny != y || nx != x)
                        DFS(board, ny, nx, cost + 1);
        }
}

int solution(vector<string> board) {

        int MAX = 10000000;
        costs.resize(board.size(), vector<int>(board[0].size(), MAX));

        int sy, sx, gy, gx;
        for (int i = 0; i < board.size(); i++)
        {
                for (int j = 0; j < board[i].size(); j++)
                {
                        if (board[i][j] == 'R')
                        {
                                sy = i;
                                sx = j;
                        }

                        if (board[i][j] == 'G')
                        {
                                gy = i;
                                gx = j;
                        }
                }
        }

        DFS(board, sy, sx, 0);
        return costs[gy][gx] == MAX ? -1 : costs[gy][gx];
}