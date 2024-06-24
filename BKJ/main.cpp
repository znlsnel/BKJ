#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> dist;
vector<vector<int>> v;

void dijkstra()
{
        priority_queue<pair<int, int>> q;
        q.push({ 0, 1 });
        dist[1] = 0;
        dist[0] = -100000;

        while (q.size())
        {
                auto [cost, node] = q.top(); q.pop();
                cost *= -1;

                for (int next : v[node])
                {
                        if (dist[next] > cost + 1)
                        {
                                dist[next] = cost + 1;
                                q.push({ -(cost + 1), next });
                        }
                }

        }

}

int solution(int n, vector<vector<int>> edge) {
        v.resize(n + 1);
        dist.resize(n + 1, 1000000000);

        for (auto& e : edge) {
                v[e[0]].push_back(e[1]);
                v[e[1]].push_back(e[0]);

        }

        dijkstra();

        int maxDist = 0;
        int cnt = 0;
        for (int d : dist)
                maxDist = max(maxDist, d);

        for (int d : dist)
                if (d == maxDist)
                        cnt++;

        //for (int i = 1; i < dist.size(); i++)
       // /    cout << i << " : " << dist[i] << "\n";





        return cnt;
}