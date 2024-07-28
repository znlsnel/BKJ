#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> v;

void DFS(int node)
{
        visited[node] = true;
        for (int next : v[node])
        {
                if (visited[next])
                        continue;
                DFS(next);
        }
}

int solution(int n, vector<vector<int>> computers) {
        visited.resize(n);
        v.resize(n);
        for (int i = 0; i < computers.size(); i++)
        {
                for (int j = 0; j < computers[i].size(); j++)
                {
                        if (i == j || computers[i][j] == 0)
                                continue;
                        v[i].push_back(j);
                }
        }
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
                if (!visited[i]) {
                        DFS(i);
                        answer++;
                }
        }

        return answer;
}