#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


void dfs(int node);
static vector<vector<int>> tree;
static int M;
int result = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	tree.resize(N + 1);
	int root = 0;

	for (int i = 0; i < N; i++)
	{
		int node;
		cin >> node;
		if (node != -1 )
			tree[node].push_back(i); 
		else
			root = i;

	}
	cin >> M;
	if (M != root)
		dfs(root);

	cout << result;
} 
 
void dfs(int node)
{
	int count = 0;
	for (int n : tree[node])
	{
		if (n == M ) 
			continue;

		count++;
		dfs(n);

	}
	if (count == 0) 
		result++;
}

