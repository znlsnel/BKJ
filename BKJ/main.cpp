#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <tuple>
using namespace std;

static vector<int> parent;
void unionFunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	int N, M;
	cin >> N >> M;
	parent.resize(N + 1);
	 
	int dosi[201][201];
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++)
			cin >> dosi[i][j];
	 
	int route[1001];
	for (int i = 1; i <= M; i++)
		cin >> route[i]; 

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) {
			if (dosi[i][j] == 1)
				unionFunc(i, j); 
		}
	}

	int index = find(route[1]);
	
	for (int i = 2; i <= M; i++)
		if (index != find(route[i])) {
			cout << "NO" << "\n";
			return 0; 
		}  

	cout << "YES" << "\n";
}   

void unionFunc(int a, int b)
{
	int A = find(a);
	int B = find(b);
	
	if (A > B)
		parent[A] = B;

	else
		parent[B] = A;
} 
 
int find(int a) 
{
	if (parent[a] != a)
		parent[a] = find(parent[a]); // 경로 압축
	return parent[a];
}

bool checkSame(int a, int b)
{
	int A = find(a);
	int B = find(b); 

	return A == B; 
}

