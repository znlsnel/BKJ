#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static long mod = 1000000000; 
static long D[1000001];
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	// N개의 a, M개의 z
		cin >> N; 


		D[1] = 0;
		D[2] = 1;
	  
		for (int i = 3; i <= N; i++) {
			D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % mod;   
		}
		cout << D[N] << "\n";

	
}
