#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <tuple>
using namespace std;

void DFS(int node);
vector<vector<int>> A;
vector<int> check;
vector<bool> visited;
bool IsEven;
 


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	  
	int N;
	cin >> N;

	for (int t = 0; t < N; t++)
	{
		int V, E;
		cin >> V >> E;
		A.resize(V + 1);
		visited.resize(V + 1);
		check.resize(V + 1);
		IsEven = true;

		for (int i = 0; i < E; i++) { 
			int S, S2; 
			cin >> S >> S2; 
			A[S].push_back(S2);
			A[S2].push_back(S);
		}  
		for (int i = 1; i <= V; i++)
		{
			if (IsEven)
				DFS(i);
			else
				break;
		}
		if (IsEven)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
		 
		for (int i = 0; i <= V; i++) {
			A[i].clear();
			visited[i] = false;
			check[i] = 0;
		} 
	}
}  
 // 1 -2 /   / 2 - 3/  / 3 - 4 / / 4 - 2
 // 0  1        1    0     0    1       1    1
void DFS(int node)
{
	visited[node] = true;

	for (int i : A[node]){
		if (!visited[i]) {
			check[i] = (check[node] + 1) % 2;
			DFS(i);
		}
		else if (check[node] == check[i]) // 사이클 발생
			IsEven = false;
	} 
}
