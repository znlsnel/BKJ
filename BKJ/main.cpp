#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


static vector<int> parent; 

void Union(int a, int b);
int find(int a); 

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;


static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, sum = 0;
	cin >> N;
	parent.resize(N);
	for (int i = 0; i < N; i++)
		parent[i] = i;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			char tempc = cin.get();
			if (tempc == '\n')
				tempc = cin.get();

			int cost = 0;
			if (tempc >= 'a' && tempc <= 'z')
				cost = tempc -  'a' + 1;

			else if (tempc >= 'A' && tempc <= 'Z')
				cost = tempc - 'A' + 27;

			sum += cost;
			if (i != j && cost > 0)
				pq.push(Edge{ i, j, cost });
		}


	int useEdge = 0;
	int result = 0;
	while (pq.size())
	{
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e))
		{
			Union(now.s, now.e);
			result += now.v;
			useEdge++;
		}
	}

	if (useEdge == N - 1)
		cout << sum - result << "\n";
	else
		cout << -1 << "\n";

}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}

int find(int a)
{
	if (a == parent[a])
		return a;
	 
	return parent[a] = find(parent[a]);
}

