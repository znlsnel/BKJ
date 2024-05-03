#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static vector<int> D, T, P;

void result(int i)
{
	
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N; 
	D.resize(N + 2, 0);
	T.resize(N + 1, 0);
	P.resize(N + 1, 0);
	 
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	} 
	
	for (int i = N; i > 0; i--)
	{
		if (i + T[i] - 1 > N) {
			D[i] = D[i + 1];
		}
		else { 
			D[i] = max(D[i + 1], P[i] + D[i + T[i]]);
		}
	}


	cout << D[1]; 
} 
 

//3 10 
//5 20 
//1 10 
//1 20 
//2 15 
//4 40 
//2 200
//
//->
//
//1
//2 
//3 10, 10
//4 20
//5 0
//6 15 , 20
//7 0
// 8 

