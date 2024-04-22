#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static vector<long> tree;
long getSum(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	int treeHeight = 0;
	int Length = N;

	while (Length != 0) {
		Length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	//int treeSize = 2;
	//for (int i = 1; i < treeHeight + 1; i++)  
	//	treeSize *= 2;

	int startNodeIndex = treeSize / 2 - 1;

	tree.resize(treeSize + 1);

	for (int i = startNodeIndex + 1; i <= startNodeIndex + N; i++)
	{
		cin >> tree[i];
	}
	setTree(treeSize - 1);

	for (int i = 0; i < M + K; i++)
	{
		long a, s, e;
		cin >> a >> s >> e;

		if (a == 1) {
			changeVal(startNodeIndex + s, e);
		}
		else if (a == 2){
			cout << getSum(startNodeIndex + s, startNodeIndex + e) << "\n";
		}


	}
}

long getSum(int s, int e)
{
	long result = 0;

	while (s <= e)
	{
		if (s % 2 == 1) 
		{
			result += tree[s];
			s++;
		}
		if (e % 2 == 0)
		{
			result += tree[e];
			e--;
		}

		s /= 2;
		e /= 2; 
	}

	return result;

}

void changeVal(int s, long value)
{
	long diff = value - tree[s];
	 
	while (s > 0)
	{
		tree[s ] += diff;
		s /= 2;
	}
}


void setTree(int i)
{
	while (i != 1)
	{
		tree[i / 2] += tree[i];
		i--;
	}
}