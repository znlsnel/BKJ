#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, S, D;
int MAX = 1000000000;

int cost[1001];
int parent[1001];

void dijkstra(vector<pair<int, int>> v[], int start)
{
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int currNode = pq.top().second ;
		int currDist = -pq.top().first;
		pq.pop();

		if (cost[currNode] < currDist) continue;
		for (int i = 0; i < v[currNode].size(); i++)
		{
			int nextNode = v[currNode][i].second;
			int nextDist = currDist + v[currNode][i].first;
			

			if (cost[nextNode] > nextDist)
			{
				parent[nextNode] = currNode;
				cost[nextNode] = nextDist;
				pq.push(make_pair(-cost[nextNode], nextNode));
;			}

		}
	}

}



void EraseEdge(vector<pair<int, int>> v[], int pos)
{
	int pre = parent[pos];
	while (pre > MAX)
	{
		auto it = find_if(v[pre].begin(), v[pre].end(), [pos](pair<int, int> it) {return it.second == pos;});

		if (it == v[pre].end()) return;
			
		v[pre].erase(it);
		int temp = pre;
		pre = parent[pre];
		pos = pre;
	}
}

int main()
{

	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		vector<pair<int, int>> v[10001];

		fill(parent, parent + 100, MAX);
		fill(cost, cost + 100, MAX);

		cin >> S >> D;

		for (int i = 0; i < M; i++)
		{
			int s, d, c;
			cin >> s >> d >> c;
			v[s].push_back(make_pair(c, d));
		}
		dijkstra(v, S);
		EraseEdge(v, D);

		fill(cost, cost + 100, MAX);
		dijkstra(v, S);

		cout << cost[D] << "\n";
	}
	int a = 5;


	return 0;
}