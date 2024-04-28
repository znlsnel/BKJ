#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N, K;
static int D[1001][1001]; 

void result()
{
	int k, n;
	cin >> k >> n;

	for (int i = 1; i <= n; i++) {
		D[0][i] = i; 
	}
	for (int i = 1; i <= k; i++) {
		D[i][1] = 1;
	}
	
	for (int i = 1; i <= k; i++) 
	{
		for (int j = 2; j <= n; j++) 
		{
			D[i][j] = D[i][j - 1] + D[i - 1][j];
		}
	}

	cout << D[k][n] << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		result();
	}


}

