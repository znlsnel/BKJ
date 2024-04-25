#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;
int executeLCA(int a, int b);
void BFS(int i);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N; 

	tree.resize(N + 1);
	depth.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1);


	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	parent[1] = 0; 
	BFS(1);
	 
	int M;
	cin >> M;

	vector<int> result;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		result.push_back(executeLCA(a, b));
	}

	for (int i : result)
		cout << i << "\n";
	 
}

int executeLCA(int a, int b)
{
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (depth[a] != depth[b])
		a = parent[a];
	
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}
  
void BFS(int i)
{ 
	// index, level
	queue<pair<int, int>> q;
	q.push(make_pair(i, 0));

	 
	while (q.size())
	{
		int index = q.front().first;
		int level = q.front().second;
		
		visited[index] = true;
		depth[index] = level;
		q.pop();

		 
		for (int i : tree[index]) {
			
			if (visited[i] == true) 
				continue;

			parent[i] = index;
			q.push(make_pair(i, level + 1)); 
		}
	}
}