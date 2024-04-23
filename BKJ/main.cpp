#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

vector<int> tree;
void SetTree(int i);
int GetMin(int s, int e);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int treeHeight = 0;
	int Length = N;

	while (Length > 0)
	{
		Length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 2));
	int startNodeId = treeSize / 2 - 1;
	tree.resize(treeSize);

	for (int i = startNodeId + 1; i <= startNodeId + N; i++)
	{
		cin >> tree[i];
	}
	SetTree(treeSize - 1);

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << GetMin(s + startNodeId, e + startNodeId) << "\n";
	}
	
}

int GetMin(int s, int e)
{
	int result = 0;

	while (s <= e)
	{
		if (s % 2 == 1) {
			result = result == 0 ? tree[s] : min(result, tree[s]);
			s++;
		}
		if (e % 2 == 0) {
			result = result == 0 ? tree[e] : min(result, tree[e]); 
			e--;
		}
		 
		s /= 2;
		e /= 2;
	}

	return result;
}

void SetTree(int i)
{
	while (i > 0)
	{
		tree[i / 2] = tree[i / 2] == 0 ? tree[i] : min(tree[i / 2], tree[i]);
		i--;
	}
}