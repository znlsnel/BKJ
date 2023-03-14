#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> vec;
vector<bool> visited;

int result = 0;

void bfs(int n);

// 11724
int main()
{
	
	int V, E;
	cin >> V >> E;
	vec.resize(V + 1);
	visited.resize(V + 1);

	for (int i = 1; i <= E; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= V; i++)
	{
		if (visited[i] == false)
		{
			bfs(i);
			result++;
		}
	}

	cout << result;
	return 0;
}

void bfs(int n)
{
	visited[n] = true;

	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int k = q.front();
		q.pop();

		for (int i = 0; i < vec[k].size(); i++)
		{
			int node = vec[k][i];
			if (visited[node]) continue;
			
			visited[node] = true;
			q.push(node);
		}
	}

}
