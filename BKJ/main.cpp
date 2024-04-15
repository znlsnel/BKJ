#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

static int N;
static long mdistance[101][101];


void Union(int a, int b);
int find(int a);
static vector<int> parent;

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	parent.resize(N + 1);

	for (int i = 0; i <= N; i ++ ) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		pq.push(Edge{ s, e, v });
	}

	int useEdge = 0;
	int result = 0;

	while (useEdge < N - 1)
	{
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e)) {
			Union(now.s, now.e);
			result = result + now.v;
			useEdge++; 
		}
	}
	cout << result;
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
