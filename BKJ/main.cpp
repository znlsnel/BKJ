#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> edge;

int N, M, K;
static int W[1001][1001];
vector<int> mdistance;
priority_queue<int> distQueue[1001];

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		W[u][v] = w; 
	} 


	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(make_pair(0, 1));
	distQueue[1].push(0);

	while (pq.size())
	{
		edge current = pq.top();
		pq.pop();

		for (int adjNode = 1; adjNode <= N; adjNode++)
		{
			if (W[current.second][adjNode] != 0) 
			{
				if (distQueue[adjNode].size() < K)
				{
					distQueue[adjNode].push(current.first + W[current.second][adjNode]);
					pq.push(make_pair(current.first + W[current.second][adjNode], adjNode));
				}
				else if (distQueue[adjNode].top() > current.first + W[current.second][adjNode])
				{
					distQueue[adjNode].pop();
					distQueue[adjNode].push(current.first + W[current.second][adjNode]);
					pq.push(make_pair(current.first + W[current.second][adjNode], adjNode));
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (distQueue[i].size() == K)
			cout << distQueue[i].top() << "\n";
		else
			cout << -1 << "\n";
	}


	return 0;
}

