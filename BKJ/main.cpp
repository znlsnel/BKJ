#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

inline int GetCost(int y, int x, int dy, int dx)
{
        if (y == dy && x == dx)
                return 1;

        int dirY = abs(dy - y);
        int dirX = abs(dx - x);

        int d = min(dirY, dirX);
        int d2 = max(dirY, dirX) - d;

        return d * 3 + d2 * 2;
}

inline void ctop(char c, int& ny, int& nx)
{
        //   cout << c << "\n";
        if (c > '0' && c <= '9')
        {
                int a = (c - '1');
                ny = a / 3;
                nx = a % 3;
        }
        else if (c == '0') {
                ny = 3;
                nx = 1;
        }
        else if (c == '*')
        {
                ny = 3;
                nx = 0;
        }
        else if (c == '#')
        {
                ny = 3;
                nx = 2;
        }
}

int dp[100001][12][12];
int DFS(const string& nums, int idx, int ly, int lx, int ry, int rx)
{
        if (idx == nums.size())
                return 0;

        if (ly == ry && lx == rx)
                return 9999999;

        int lnum = ly * 3 + lx + 1;
        int rnum = ry * 3 + rx + 1;
        if (dp[idx][lnum][rnum] != 0)
                return dp[idx][lnum][rnum];

        int ny, nx;
        ctop(nums[idx], ny, nx);
        int cost_1 = GetCost(ly, lx, ny, nx);
        int cost_2 = GetCost(ry, rx, ny, nx);

        int p1 = cost_1 + DFS(nums, idx + 1, ny, nx, ry, rx);
        int p2 = cost_2 + DFS(nums, idx + 1, ly, lx, ny, nx);

        return dp[idx][lnum][rnum] = min(p1, p2);
}

int solution(string numbers) {
        return DFS(numbers, 0, 1, 0, 1, 2);
}

// 제자리 1
// 상하좌우 2
// 대각 3