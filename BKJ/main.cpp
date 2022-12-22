#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
int MAX = 1000000000;

int vecCost[1001];
int revCost[1001];

vector<pair<int, int>> vec[10001];
vector<pair<int, int>> rev[10001];

void dijkstra(vector<pair<int, int>> v[], int cost[],  int start)
{
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int current = pq.top().second ;
		int currDist = -pq.top().first;
		pq.pop();

		if (cost[current] < currDist) continue;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].second - 1;
			int nextDist = currDist + v[current][i].first;
			if (cost[next] > nextDist)
			{
				cost[next] = nextDist;
				pq.push(make_pair(-cost[next], next));
;			}
		}
	}

}

int main()
{
	cin >> N >> M >> X;

	fill(vecCost, vecCost + N, MAX);
	fill(revCost, revCost + N, MAX);

	for (int i = 0; i < M; i++)
	{
		int s, d, c;
		cin >> s >> d >> c;
		vec[s - 1].push_back(make_pair(c, d));
		rev[d - 1].push_back(make_pair(c, s));
	}

	dijkstra(vec, vecCost, X - 1);
	dijkstra(rev, revCost, X - 1);


	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < vecCost[i] + revCost[i])
			max = vecCost[i] + revCost[i];
	}

	cout << max;

	return 0;
}