#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
        int s, d, cost;
        Edge(int a, int b, int c) : s(a), d(b), cost(c) {}
        bool operator < (Edge other)
        {
                return cost < other.cost;
        }
};

vector<int> parent;

int Find(int a)
{
        if (parent[a] == a)
                return a;

        return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
        a = Find(a);
        b = Find(b);

        parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {

        vector<Edge> edges;
        for (auto& cost : costs)
                edges.push_back({ cost[0], cost[1], cost[2] });

        sort(edges.begin(), edges.end());
        parent.resize(n);
        for (int i = 0; i < n; i++)
                parent[i] = i;

        int answer = 0;
        for (Edge& edge : edges)
        {
                if (Find(edge.s) != Find(edge.d))
                {
                        Union(edge.s, edge.d);
                        answer += edge.cost;
                }
        }


        return answer;
}