#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, result = 100000000;
vector<vector<int>> map;
vector<int> rot;
vector<int> dx = { 0, 0, 0, 1, -1 };
vector<int> dy = { 0, 1, -1, 0, 0 };

void dfs(int ind)
{
        if (ind == N)
        {
                vector<vector<int>> tmp(N, vector<int>(N));
                vector<int> cur(N);

                for (int i = 0; i < N; i++)
                        cur[i] = rot[i];

                for (int i = 0; i < N; i++)
                {
                        for (int j = 0; j < N; j++)
                                tmp[i][j] = map[i][j];
                }

                int tmpRes = 0;
                for (int i = 0; i < N; i++)
                {
                        for (int j = 0; j < N; j++)
                        {
                                tmpRes += cur[j];
                                for (int d = 0; d < 5; d++)
                                {
                                        int X = i + dx[d];
                                        int Y = j + dy[d];

                                        if (X < 0 || Y < 0 || X >= N || Y >= N)
                                                continue;

                                        tmp[X][Y] = tmp[X][Y] - cur[j] >= 0 ? tmp[X][Y] - cur[j] : tmp[X][Y] - cur[j] + 4;
                                }
                        }

                        for (int j = 0; j < N; j++)
                                cur[j] = tmp[i][j];
                }

                bool flag = true;
                for (int i = 0; i < N; i++)
                {
                        if (cur[i] != 0)
                        {
                                flag = false;
                                break;
                        }
                }

                if (flag)
                        result = min(result, tmpRes);

                return;
        }

        for (int i = 0; i < 4; i++) {
                rot[ind] = i;
                dfs(ind + 1);
        }
}

int solution(vector<vector<int>> clockHands) {
        N = clockHands.size();
        map = vector<vector<int>>(N, vector<int>(N));
        rot = vector<int>(N);

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                        map[i][j] = (4 - clockHands[i][j]) % 4;
        }

        dfs(0);
        return result;
}

