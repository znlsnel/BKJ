#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <list>
using namespace std;

int N, M, S, D;
int MAX = 1000000000;

int cost[1001];
int parent[1001];

bool path[1001][1001];

int leastCost = MAX;

void addPath()
{
	int current = D;
	int pre = parent[D];

	while (pre != MAX)
	{
		path[pre][current] = true;

		int temp = pre;
		pre = parent[pre];
		current = temp;
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
		for (int i = 0; i < v[currNode].size(); i++)
		{
			int nextNode = v[currNode][i].second;
			int nextDist = currDist + v[currNode][i].first;

			if (path[currNode][nextNode])continue;
			

			if (cost[nextNode] >= nextDist)
			{
				parent[nextNode] = currNode;
				if (nextNode == D && nextDist == leastCost) addPath();
				cost[nextNode] = nextDist;
				pq.push(make_pair(-cost[nextNode], nextNode));
;			}

		}
	}

}


// 굳이 지울필요가 있을까!?  --- 핵심 point
void EraseEdge(vector<pair<int, int>> v[], int dest)
{
	int end = dest;
	int leastCost = cost[end];
	int pre = parent[end];
	int currCost = leastCost;

	while (pre < MAX)
	{
		int a = end;
		auto it = find_if(v[pre].begin(), v[pre].end(), [a](pair<int, int> it) {return it.second == a;});

		if (it == v[pre].end()) return;

		v[pre].erase(it);
		int temp = pre;
		pre = parent[pre];
		end = temp;

		// TODO 
		// vector의 경우 find_if 랑 erase의 속도가 O(N)이기 때문에 개선이 필요함
		//  deque의 경우 erase는 괜찮지만 find_if는 안됨
		
	}

	
	fill(cost, cost + N, MAX);
	dijkstra(v);
	currCost = cost[dest];
	
	if (currCost == leastCost)
		EraseEdge(v, dest);
	
}

int main()
{

	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		
		vector<pair<int, int>> v[10001];
		
		fill(parent, parent + N, MAX);
		fill(cost, cost + N, MAX);

		for (int i = 0; i < N; i++)
			fill(path[i], path[i] + N, false);

		cin >> S >> D;

		for (int i = 0; i < M; i++)
		{
			int s, d, c;
			cin >> s >> d >> c;
			v[s].push_back(make_pair(c, d));
		}

		dijkstra(v);

		leastCost = cost[D];
		fill(cost, cost + N, MAX);
		dijkstra(v);

		fill(cost, cost + N, MAX);
		dijkstra(v);

		int result = cost[D] == MAX ? -1 : cost[D];
		cout << result << "\n";
	}
	


	return 0;
}