#include <string>
#include <vector>

using namespace std;

int DFS(int k, vector<vector<int>>& d, vector<bool>& visited, int cnt)
{
        int ret = 0;

        for (int i = 0; i < d.size(); i++)
        {
                if (visited[i] || k < d[i][0])
                        continue;

                visited[i] = true;
                ret = max(ret, DFS(k - d[i][1], d, visited, cnt + 1) + 1);
                visited[i] = false;
        }

        return ret;
}

int solution(int k, vector<vector<int>> dungeons) {
        vector<bool> visited(dungeons.size());

        return DFS(k, dungeons, visited, 0);
}