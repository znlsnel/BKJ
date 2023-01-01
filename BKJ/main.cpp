#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define edge pair<int, int>
#define MAX 500000001
using namespace std;

int N, M, S, D;

vector<vector<edge>> v;

bool path[501][501];
bool  isSecond = false;


void addPath(vector<vector<int>> &parent, int curr)
{
	queue<int> q;
	q.push(curr);

	while (!q.empty())
	{
		int child = q.front();
		q.pop();
		for (int pre : parent[child])
		{
			if (path[pre][child]) continue;
			path[pre][child] = true;
			q.push(pre);
		}
	}
}



void addPath2(vector<vector<int>>& parent, int curr)
{
	for (int pre : parent[curr])
	{
		if (path[pre][curr]) continue;
		path[pre][curr] = true;
		addPath2(parent, pre);
	}
	
	
}

int dijkstra()
{
	vector<int> cost(N + 1, MAX);
	vector<vector<int>> parent(N + 1);

	cost[S] = 0;
	priority_queue<edge> pq;
	pq.push(make_pair(0, S));

	while (!pq.empty())
	{
		int currNode = pq.top().second;
		int currDist = -pq.top().first;
		pq.pop();

		if (cost[currNode] < currDist) continue;


		for (auto a : v[currNode])
		{
			if (path[currNode][a.second]) continue;

			int nextNode = a.second;
			int nextDist = cost[currNode] + a.first;

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

	int result = cost[D];

	if (!isSecond) addPath2(parent, D);
	if (result == MAX) result = -1;

	return result;
}

bool input()
{
	v.clear();
	std::cin >> N >> M;
	if (N == 0 && M == 0) return false;

	isSecond = false;
	for (int i = 0; i < N; i++)
		fill(path[i], path[i] + N, false);
	
	std::cin >> S >> D;
	v = vector<vector<edge>>(N + 1);

	for (int i = 0; i < M; i++)
	{
		int s, d, c;
		std::cin >> s >> d >> c;
		v[s].push_back(make_pair(c, d));
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (input())
	{

		// 최단 경로 탐색
		// 모든 최단 경로 지우기
		dijkstra();

		isSecond = true;
		// 거의 최단 경로 탐색
		cout << dijkstra() << '\n';
	}



	return 0;
}