#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <tuple>
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
vector<int> result;
 
void BFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	  
	long nodeCount, edgeCount;
	cin >> nodeCount >> edgeCount;

	nodes.resize(nodeCount + 1);
	visited.resize(nodeCount + 1);  
	result.resize(nodeCount + 1);
	for (int i = 0; i < edgeCount; i++) {
		int e, v;
		cin >> e >> v;
		nodes[e].push_back(v);  
	}
	 
	for (int i = 0; i <= nodeCount; i++) {
		fill(visited.begin(), visited.end(), false);
		BFS(i); 
	} 

	int maxVal = 0;
	for (int i = 0; i <= nodeCount; i++)
		maxVal = max(maxVal, result[i]);

	for (int i = 1; i <= nodeCount; i++) {
		if (result[i] == maxVal)
			cout << i << " "; 
	}
	
}  
   
void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (q.size())
	{
		int curNode = q.front();
		q.pop();

		for (int node : nodes[curNode])
		{
			if (visited[node] == false) {
				visited[node] = true; 
				result[node]++;
				q.push(node);  
			}
		}
	}

}