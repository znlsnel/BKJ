#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(vector<int>& dp, int num, int target, int n, int cost)
{
        if ((dp[num] != -1 && dp[num] <= cost) ||
                num > target)
                return;

        dp[num] = cost;
        // cout << num << "\n";

        if (num == target)
                return;

        DFS(dp, num + n, target, n, cost + 1);
        DFS(dp, num * 2, target, n, cost + 1);
        DFS(dp, num * 3, target, n, cost + 1);
}

int solution(int x, int y, int n) {
        int answer = 0;
        vector<int> dp(y * 10, -1);

        DFS(dp, x, y, n, 0);


        return dp[y];
}