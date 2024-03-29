#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <tuple>
using namespace std;

vector < bool> visited;
vector<int> result;
vector<vector<int>> nodes;

int goalDist;
void BFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	  
	long nodeCount, edgeCount, startVtx;
	cin >> nodeCount >> edgeCount >> goalDist >> startVtx;

	nodes.resize(nodeCount + 1);
	visited.resize(nodeCount + 1);  

	for (int i = 0; i < edgeCount; i++) {
		int e, v;
		cin >> e >> v;
		nodes[e].push_back(v);  
	}
	  
	BFS(startVtx);
	 
	sort(result.begin(), result.end());
	for (int node : result)
		cout << node << "\n";

	if (result.size() == 0)
		cout << -1 << "\n";
} 
   
void BFS(int node)
{
	queue<pair<int, int>> q;
	q.push(make_pair(node, 0));
	
	while (q.size())
	{
		int curNode = q.front().first;
		int curDist = q.front().second; 
		q.pop();

		visited[curNode] = true; 

		if (curDist == goalDist) {
			result.push_back(curNode);
			continue;
		}

		for (int node : nodes[curNode])
		{
			if (visited[node] == false) {
				q.push(make_pair(node, curDist + 1)); 
				visited[node] = true; 
			}
		}
	}

}