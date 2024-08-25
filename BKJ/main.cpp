#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Check(vector<vector<int>>& board, int y, int x)
{
        return y >= 0 && y < board.size() && x >= 0 && x < board[0].size() && board[y][x] == 1;
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int DFS(vector<vector<int>>& board, int y, int x, int oy, int ox)
{
        if (board[y][x] == 0) {
                cout << y << ", " << x << "\n";
                return 0;

        }

        int cnt = 0;

        board[y][x] = 0;

        for (int i = 0; i < 4; i++)
        {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (!Check(board, ny, nx))
                        continue;

                // return 값이 0이면 진거
                int value = DFS(board, oy, ox, ny, nx) + 1;

                // 패배였는데 이기는 경우가 있다면
                if (cnt % 2 == 0 && value % 2 == 1)
                        cnt = value;

                // 무조건 진다면 ? 최대한 도망
                else if (cnt % 2 == 0 && value % 2 == 0)
                        cnt = max(cnt, value);

                // 무조건 승리 ? 최대한 빠르게
                else if (cnt % 2 == 1 && value % 2 == 1)
                        cnt = min(cnt, value);
        }

        board[y][x] = 1;
        return cnt;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
        return DFS(board, aloc[0], aloc[1], bloc[0], bloc[1]);
}