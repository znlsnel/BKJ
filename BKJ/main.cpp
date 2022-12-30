#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> v[100001];

int N, M, S, D;
int MAX = 1000000000;

int cost[1001];


vector<int> parent[1001];

bool path[501][5001];

bool  isSecond = false;



void addPath(int curr)
{

	for (int pre : parent[curr])
	{
		path[pre][curr] = true;
		addPath(pre);
	}
}


void dijkstra(vector<pair<int, int>> v[])
{
	cost[S] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, S));

	while (!pq.empty())
	{
		int currNode = pq.top().second;
		int currDist = -pq.top().first;
		pq.pop();

		if (cost[currNode] < currDist) continue;


		for (auto a : v[currNode])
		{
			int nextNode = a.second;
			int nextDist = currDist + a.first;

			if (isSecond && path[currNode][nextNode]) continue;

			if (cost[nextNode] == nextDist)
			{
				parent[nextNode].push_back(currNode);
			}

			else if (cost[nextNode] > nextDist)
			{
				parent[nextNode].clear();
				parent[nextNode].push_back(currNode);
				
				cost[nextNode] = nextDist;
				pq.push(make_pair(-cost[nextNode], nextNode));

			}
		}
	}
	if (!isSecond) addPath(D);

}




int main()
{
	vector<int> rv;

	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; i++)
			v[i].clear();

		isSecond = false;
		std::fill(cost, cost + N, MAX);

		for (int i = 0; i < N; i++)
			std::fill(path[i], path[i] + N, false);

		cin >> S >> D;

		for (int i = 0; i < M; i++)
		{
			int s, d, c;
			cin >> s >> d >> c;
			v[s].push_back(make_pair(c, d));
		}

		// 최단 경로 탐색
		// 최단 경로 지우기
		dijkstra(v);

		// 거의 최단 경로 탐색
		std::fill(cost, cost + N, MAX);
		isSecond = true;
		dijkstra(v);

		int result = cost[D] == MAX ? -1 : cost[D];
		rv.push_back(result);
	}

	for (auto a : rv)
		cout << a << "\n";

	return 0;
}