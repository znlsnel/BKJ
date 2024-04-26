#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

vector<vector<int>> tree;
vector<int> depth;
vector<bool> visited;
static int parent[21][100001];
static int kmax;

void BFS(int i);
int LCA(int a, int b);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N; 
	tree.resize(N + 1);
	depth.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	 }

	int temp = 1;
	kmax = 0;
	while (temp <= N) {
		temp <<= 1;
		kmax++;
	}

	BFS(1);

	for (int k = 1; k <= kmax; k++) {
		for (int n = 1; n <= N; n++) {
			parent[k][n] = parent[k - 1][parent[k - 1][n]];
		}
	}

	
	vector<int> result;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		result.push_back(LCA(a, b));
	}
	for (int i : result)
		cout << i << "\n";

}
int LCA(int a, int b) {
	if (depth[a] > depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}

	for (int k = kmax; k >= 0; k--)
	{
		if (pow(2, k) <= depth[b] - depth[a]) {
			if (depth[a] <= depth[parent[k][b]])
				b = parent[k][b];
		}
	}
	for (int k = kmax; k >= 0 && a != b; k--) {
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}
	int LCA = a;
	if (a != b)
		LCA = parent[0][LCA];

	return LCA;
}

 

void BFS(int i)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, 0));

	while (q.size())
	{
		int curId = q.front().first;
		int curLevel = q.front().second;
		q.pop();

		visited[curId] = true;
		depth[curId] = curLevel;

		for (int i : tree[curId]) {
			if (visited[i])
				continue;

			parent[0][i] = curId; 


			q.push(make_pair(i, curLevel + 1));
		}
	}
}

