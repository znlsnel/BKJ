#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, S, D;
int MAX = 1000000000;



vector<int> parent[501];

bool path[501][501];
bool  isSecond = false;

int cost[1001];


queue<int> q;
void addPath(int curr)
{
	q.push(curr);

	while (!q.empty())
	{
		int child = q.front();
		q.pop();
		for (int pre : parent[child])
		{
			path[pre][child] = true;
			q.push(pre);
		}
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

			if (path[currNode][nextNode]) continue;

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
		std::cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		vector<pair<int, int>> v[10001];
		isSecond = false;

		for (int i = 0; i < N; i++)
			std::fill(path[i], path[i] + N, false);

		std::fill(cost, cost + N, MAX);


		std::cin >> S >> D;
		for (int i = 0; i < M; i++)
		{
			int s, d, c;
			std::cin >> s >> d >> c;
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