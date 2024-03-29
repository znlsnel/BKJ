#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <tuple>
using namespace std;


vector<tuple<int, int, int>> A[10]; // 인접 리스트
long lcm; // 최소 공배수
bool visited[10]; // DFS 탐색 시 탐색 여부 저장 배열
long D[10]; // 각 노드 값 저장 배열
long gcd(long a, long b);
void DFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	 
	// 2 3 5 6 7 8 10
	int N;
	cin >> N;
	lcm = 1;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		A[a].push_back(make_tuple(b, p, q));
		A[b].push_back(make_tuple(a, q, p));

		lcm *= (p * q / gcd(p, q)); 
	}

	D[0] = lcm;
	DFS(0);
	long mgcd = D[0];

	for (int i = 1; i < N; i++) 
	{
		mgcd = gcd(mgcd, D[i]);
	}
	for (int i = 0; i < N; i++)
		cout << D[i] / mgcd << " ";
}
  
long gcd(long a, long b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b); 
}

void DFS(int node)
{
	visited[node] = true;

	for (tuple<int, int, int> i :  A[node]) {
		int nextID = get<0>(i);
		if (visited[nextID] == false) { 
			 
		//	D[nextID] =  D[node] / ((float)get<1>(nextNode) / (float)get<2>(nextNode)); 
			D[nextID] =  D[node] * get<2>(i) / get<1>(i);  
			DFS(nextID); 
		}
	}
}
