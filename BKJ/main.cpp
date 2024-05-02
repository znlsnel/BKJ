#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static vector<int> D;

int fibo(int n)
{
	if (D[n] != -1) {
		return D[n];
	}

	return D[n] = fibo(n - 2) + fibo(n - 1); 
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N; 
	D.resize(N + 1, -1);
	 
	D[0] = 0; 
	D[1] = 1;
	  
	
	fibo(N);
	cout << D[N] << "\n"; 
} 
 