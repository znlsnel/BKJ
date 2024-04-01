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

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int question, a, b;
		cin >> question >> a >> b;
		
		if (question == 0)
			unionFunc(a, b);
		else
		{
			string result = checkSame(a, b) ? "YES" : "NO";
			cout << result << "\n";
		}
	}
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

