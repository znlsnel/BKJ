#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v[32001];
int inDegree[32001];

int N, M;

void TopologySort();

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

void TopologySort()
{
	queue<int> q; 
	for (int i = 1; i <= N; i++) 
	{
		if (inDegree[i] == 0)
			q.push(i);
	} 

	while (q.size())
	{
		int n = q.front();
		q.pop(); 

		cout << n << " ";

		for (int i = 0; i < v[n].size(); i++)  
		{
			int id = v[n][i];
			if (--inDegree[id] == 0)
				q.push(id) ;
		}
	}

}