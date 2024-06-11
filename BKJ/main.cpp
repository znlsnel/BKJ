#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

int maxSheep;
void DFS(vector<int>& info, int node, int sheep, int wolf)
{
        if (sheep > 0 && sheep == wolf)
                return;

        if (info[node] == 0)
                sheep++;
        else
                wolf++;

        if (maxSheep < sheep)
                maxSheep = sheep;

        for (int i = 0; i < v[node].size(); i++)
        {
                vector<int> addNodes;
                for (int j = 0; j < v[node].size(); j++)
                {
                        if (i == j)
                                continue;

                        addNodes.push_back(v[node][j]);
                }

                int cnt = addNodes.size();
                int next = v[node][i];

                for (int i = 0; i < cnt; i++)
                {
                        v[next].push_back(addNodes[i]);
                }

                DFS(info, next, sheep, wolf);

                for (int i = 0; i < cnt; i++)
                        v[next].pop_back();
        }
}

int solution(vector<int> info, vector<vector<int>> edges) {
        v.resize(info.size());

        for (int i = 0; i < edges.size(); i++)
                v[edges[i][0]].push_back(edges[i][1]);

        DFS(info, 0, 0, 0);

        return maxSheep;
}