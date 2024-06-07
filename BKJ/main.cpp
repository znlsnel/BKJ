#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

vector<int> costs;
vector<int> answer;
vector<bool> tops;

vector<vector<pair<int, int>>> v;

void dijkstra(vector<int>& gates)
{
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (int gate : gates)
        {
                q.push(make_pair(0, gate));
                costs[gate] = 0;
        }

        while (!q.empty())
        {
                int node = q.top().second;
                int cost = q.top().first;
                q.pop();

                if (answer[0] > 0 && answer[1] < cost)
                        continue;

                if (tops[node])
                {
                        // cout << node << "\n";
                        if (answer[0] == -1 || answer[1] > cost)
                        {
                                answer[0] = node;
                                answer[1] = cost;
                        }
                        else if (answer[1] == cost && node < answer[0])
                                answer[0] = node;

                        continue;
                }
                //     cout << node << "\n";
                    // cout << v[node].size() << "\n";
                for (pair<int, int> next : v[node])
                {
                        int nextCost = max(next.second, cost);
                        if (costs[next.first] == -1 || nextCost < costs[next.first])
                        {
                                q.push(make_pair(nextCost, next.first));
                                costs[next.first] = nextCost;
                        }
                }
        }

}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

        v.resize(n + 1);
        tops.resize(n + 1, false);
        answer.resize(2, -1);
        costs.resize(n + 1, -1);

        for (int t : summits) {
                tops[t] = true;
        }

        for (int i = 0; i < paths.size(); i++)
        {
                v[paths[i][0]].push_back(make_pair(paths[i][1], paths[i][2]));
                v[paths[i][1]].push_back(make_pair(paths[i][0], paths[i][2]));
        }
        dijkstra(gates);


        return answer;
}