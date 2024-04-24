#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

vector<long> tree;
static int MOD = 1000000007;
void SetTree(int i);
long GetMul(int s, int e);
void ChangeValue(int index, long value);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int treeHeight = 0;
	int Length = N;

	while (Length > 0)
	{
		Length /= 2;
		treeHeight++;
	}
	 
	int treeSize = int(pow(2, treeHeight + 1));
	int startNodeId = treeSize / 2 - 1;
	tree.resize(treeSize + 1);  
	fill(tree.begin(), tree.end(), 1);

	for (int i = startNodeId + 1; i <= startNodeId + N; i++)
	{
		cin >> tree[i];
	}
	SetTree(treeSize - 1);

	for (int i = 0; i < M + K; i++)
	{
		long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ChangeValue(b + startNodeId, c); 
		}
		else if (a == 2)
			cout << GetMul(b + startNodeId, c + startNodeId) << "\n";

	}
	 
}
  
void ChangeValue(int index, long value)
{
	tree[index] = value;
	 
	while (index > 1) { 
		index =  index / 2;
		tree[index] = tree[index * 2] % MOD * tree[index * 2 + 1] % MOD; 
	}
}

long GetMul(int s, int e)
{
	long result = 1;
	 
	while (s <= e)
	{
		if (s % 2 == 1) {
			result = result * tree[s] % MOD;
			s++;
		}
		if (e % 2 == 0) {   
			result = result *  tree[e] % MOD;
			e--;
		}
		 
		s /= 2; 
		e /= 2; 
	}

	return result; 
}

void SetTree(int index)
{ 
	while (index != 1)
	{
		tree[index / 2] = tree[index / 2] * tree[index] % MOD;
	
		index--; 
	}
}