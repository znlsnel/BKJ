#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> inDegree;
vector<int> costs;
int N;

void TopologySort();

int main()
{
	cin >> N;

	v.resize(N + 1);
	inDegree.resize(N + 1);
	costs.resize(N + 1);

	int parent;
	for (int i = 1; i <= N; i++)
	{
		cin >> costs[i];

		while (true)
		{
			cin >> parent;
			if (parent == -1)
				break;

			v[parent].push_back(i);
			inDegree[i]++;
		}
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

	vector<int> addTimes(N + 1);
	while (q.size())
	{
		int n = q.front();
		q.pop();

		for (int id : v[n])
		{
			addTimes[id] = max(addTimes[id], costs[n] + addTimes[n]);
			if (--inDegree[id] == 0)
				q.push(id);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << addTimes[i] + costs[i] << "\n";


}