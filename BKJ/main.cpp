#include <string>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(vector<vector<int>>& roads, vector<int>& dists, int start)
{
        dists[start] = 0;

        priority_queue<pair<int, int>> q;
        q.push({ 0, start });

        while (!q.empty())
        {
                auto [cost, node] = q.top(); q.pop();
                cost *= -1;

                for (int& next : roads[node])
                {
                        if (dists[next] == -1 || dists[next] > cost + 1)
                        {
                                dists[next] = cost + 1;
                                q.push({ -(cost + 1), next });
                        }
                }
        }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
        vector<vector<int>> _roads(n + 1);
        for (auto& r : roads)
        {
                _roads[r[0]].push_back(r[1]);
                _roads[r[1]].push_back(r[0]);
        }

        vector<int> dists(n + 1, -1);
        dijkstra(_roads, dists, destination);

        for (int& s : sources)
                s = dists[s];

        return sources;
}