#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v[32001];
int inDegree[32001];

int N, M;

void TopologySort()
{

	queue<int> q;

	for (int i = 1; i <= N; i++)
		if (inDegree[i] == 0) q.push(i);

	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		cout << a << ' ';

		for (int j = 0; j < v[a].size(); j++)
		{
			int b = v[a][j];
			if (--inDegree[b] == 0)
			{
				q.push(b);
			}
		}
	}

}

int main()
{
	cin >> N >> M;
	int a, b;
	
	for (int i = 0; i < M; i++) 
	{
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++;
	}
	
	TopologySort();
	return 0;
}