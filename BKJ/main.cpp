#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


void dfs(int node);
static vector<int> parent;
static vector<bool> visited; 
static vector<vector<int>> tree;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	parent.resize(N + 1, 0);
	visited.resize(N + 1, false);
	tree.resize(N + 1);

	for (int i = 0; i < N- 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	parent[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";
}

void dfs(int node)
{

	for (int n : tree[node])
	{
		if (parent[n] != 0) continue;

		parent[n] = node;
		dfs(n);

	}
}

