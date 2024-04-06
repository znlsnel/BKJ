#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> edge;

vector<vector<edge>> edges;
priority_queue<edge, vector<edge>, greater<edge>> q;
vector<int> mdistance;
vector<int> parent;
vector<bool> visited;

int main()
{
	int V, E;
	cin >> V >> E;
	edges.resize(V + 1);
	parent.resize(V + 1);
	visited.resize(V + 1, false);
	mdistance.resize(V + 1, 100000000);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges[u].push_back(make_pair(v, w));
	}

	int S, D;
	cin >> S >> D;
	q.push(make_pair(0, S));
	mdistance[S] = 0;

	while (q.size())
	{
		edge current = q.top();
		q.pop();
		int curNode = current.second;

		if (visited[curNode])
			continue;

		visited[curNode] = true;

		for (edge e : edges[curNode]) {
			int nextDist = e.second + mdistance[curNode];
			if (nextDist < mdistance[e.first]) {
				mdistance[e.first] = nextDist;
				q.push(make_pair(mdistance[e.first], e.first));
			}
		}
	}
	cout << mdistance[D] << "\n";

	//for (int i = 1; i <= V; i++)
	//{
	//	if (visited[i])
	//		cout << mdistance[i] << "\n";
	//	else
	//		cout << "INF" << "\n"; 
	//}

	return 0;
}

