#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> _tree;
static vector<int> _distance;
static vector<bool> _visited;

void BFS(int node);

int main()
{
	int N;
	cin >> N;

	_tree.resize(N + 1);
	_distance.resize(N + 1, 0);
	_visited.resize(N + 1, false);

	for (int i = 0; i < N; i++)
	{
		int E;
		cin >> E;
		while (true)
		{
			int V, S;
			cin >> V;

			if (V == -1) 
				break;

			cin >> S; 
			_tree[E].push_back(edge(V, S));
		}
	}
	int farthestPoint = 1;
	BFS(1);
	for (int i = 2; i < N + 1; i++)
	{
		if (_distance[farthestPoint] < _distance[i])
			farthestPoint = i;
	}
	fill(_distance.begin(), _distance.end(), 0);
	fill(_visited.begin(), _visited.end(), false);

	BFS(farthestPoint);

	sort(_distance.begin(), _distance.end());
	cout << _distance[N] << "\n";
}
 
 
void BFS(int node)
{
	queue<int> q;
	q.push(node);
	_visited[node] = true;
	 
	while (q.size())
	{
		int curNode = q.front();
		q.pop();

		for (edge e : _tree[curNode])
		{
			if (_visited[e.first] == false)
			{
				_visited[e.first] = true;
				_distance[e.first] = _distance[curNode] + e.second;
				q.push(e.first);
			}
		}
	}


}