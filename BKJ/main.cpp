#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N, M, K;
static long C[202][202];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	// N개의 a, M개의 z
	cin >> N >> M >> K;
	
	for (int i = 0; i <= 200; i++) {
		C[i][i] = 1;
		C[i][0] = 1; 
		C[i][1] = i; 
	} 
	for (int i = 3; i <= 200; i++) { 
		for (int j = 2; j <= i; j++) { 
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];  
			if (C[i][j] > 1000000000)
				C[i][j] = 1000000001;
		}
	}



	// 100 * 100 
	// 1, 2, 3, 4, 5
	// 120, 24, 6, 2, 1
	 // N = 2, M = 2, K = 6라고 할때
	 //
	 // 24 6 2 1
	// N이 앞에 올 경우의 수 = 3 
	// M이 앞에 올 경우의 수 = 3
	// N N M M
	// N M N M  
	// N M M N   
	// M M N N  
	// M N M M
	// M N N M

	if (C[N + M][M] < K) {
		cout << "-1";
		return 0;
	}


	vector<char> result;
	int k = K;
	while (N + M) { 
		// n이 앞 나올 경우의 수 
		long n = C[N - 1 + M][M];   

		if (k <= n) {  
			result.push_back('a');
			N--;
		}  
		else {
			result.push_back('z');
			M--; 
			k -= n;
		}  
	}

	for (char r : result)
		cout << r; 

}

