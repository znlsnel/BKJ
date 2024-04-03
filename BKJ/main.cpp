#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <tuple>
using namespace std;

static vector<int> parent;
static vector<int> trueP;
static vector<vector<int>> party;
static int result;

void unionFunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	int N, M, T;
	cin >> N >> M >> T;
	trueP.resize(T);
	party.resize(M);
	parent.resize(N + 1);
	  
	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < T; i++)
		cin >> trueP[i];

	for (int i = 0; i < M; i++)
	{
		int party_size;
		cin >> party_size;

		for (int j = 0; j < party_size; j++)
		{
			int temp;
			cin >> temp;
			party[i].push_back(temp);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int firstPeople = party[i][0];
		for (int j = 1; j < party[i].size(); j++)
			unionFunc(firstPeople, party[i][j]); 
	}

	for (int i = 0; i < M; i++)
	{
		bool isPossible = true;
		int cur = party[i][0];
		for (int j = 0; j < T; j++)
		{
			if (find(cur) == find(trueP[j]))
			{
				isPossible = false;
				break;
			}
		}
		if (isPossible)
			result++;
	}
	cout << result << "\n";
	
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

