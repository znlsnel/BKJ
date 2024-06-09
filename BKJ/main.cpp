#include <bits/stdc++.h>
using namespace std;

struct Pos
{
        int x;
        int y;

        Pos operator + (Pos other)
        {
                Pos ret;
                ret.x = x + other.x;
                ret.y = y + other.y;
                return ret;
        }
};

int N, M;
vector<vector<bool>> visited;

Pos dir[4] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

bool OOB(Pos p)
{
        return (p.x >= 0 && p.x < N) && (p.y >= 0 && p.y < M);
}

int dfs(vector<vector<int>>& board, Pos plr, Pos opp)
{
        if (visited[plr.x][plr.y])
                return 0;

        int result = 0;

        for (int i = 0; i < 4; i++)
        {
                Pos next = plr + dir[i];
                if (OOB(next) == false ||
                        visited[next.x][next.y] ||
                        board[next.x][next.y] == 0)
                        continue;

                visited[plr.x][plr.y] = true;
                // dfs가 반환하는 값 % 2 == 0 ? 패배 : 승리
                int val = dfs(board, opp, next) + 1;
                // 위 코드는 상대의 관점이기 때문에
                // dfs() % 2 == 0 ? 나의 승리 : 나의 패배
                // + 1을 해주었기에 다시 뒤집힘
                visited[plr.x][plr.y] = false;

                if (result % 2 == 0 && val % 2 == 1)
                        result = val;

                // 무조건 패배 -> 최대한 오래 살아남기
                else if (result % 2 == 0 && val % 2 == 0)
                        result = max(result, val);

                // 무조건 승리 -> 최대한 빨리 끝내기
                else if (result % 2 == 1 && val % 2 == 1)
                        result = min(result, val);
        }

        return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
        N = board.size();
        M = board[0].size();
        visited.resize(board.size(), vector<bool>(board[0].size()));

        return dfs(board, Pos{ aloc[0], aloc[1] }, Pos{ bloc[0], bloc[1] });
}