#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

bool CHECK(vector<vector<int>>& board, int y, int x)
{
        return y >= 0 && y < board.size() && x >= 0 && x < board[y].size() && board[y][x] == 0;
}

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int dijkstra(vector<vector<int>>& board)
{
        // cost, node, type (아래 - 0, 옆 - 1);
        vector<vector<int>> dist0(board.size(), vector<int>(board[0].size(), 1000000000));
        vector<vector<int>> dist1(board.size(), vector<int>(board[0].size(), 1000000000));

        priority_queue<tuple<int, int, int, int>> q;
        q.push({ 0, 0, 0, 0 });
        q.push({ 0, 0, 0, 1 });
        dist0[0][0] = 0;
        dist1[0][0] = 0;


        while (!q.empty())
        {
                auto [cost, cy, cx, type] = q.top(); q.pop();
                cost *= -1;

                for (int i = 0; i < 4; i++)
                {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];
                        if (!CHECK(board, ny, nx))
                                continue;

                        int nextType = ny == cy ? 1 : 0;
                        int nextCost = nextType == type ? cost + 100 : cost + 600;

                        if (nextType == 0 && dist0[ny][nx] > nextCost)
                        {
                                dist0[ny][nx] = nextCost;
                                q.push({ -(nextCost), ny, nx, nextType });
                        }
                        else if (nextType == 1 && dist1[ny][nx] > nextCost)
                        {
                                dist1[ny][nx] = nextCost;
                                q.push({ -(nextCost), ny, nx, nextType });
                        }
                }
        }

        int y = board.size() - 1;
        int x = board[0].size() - 1;
        return min(dist0[y][x], dist1[y][x]);
}

// 0 0 1 0
// 0 0 0 0
// 0 1 0 1
// 1 0 0 0

int solution(vector<vector<int>> board) {
        return dijkstra(board);
}