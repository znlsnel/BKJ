#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<string> split(string example, char s);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int M , N;
	cin >> M >> N;

	vector<int> A(N + 1); 
	 
	for (int i = 2; i <= N; i++)
		A[i] = i; 
	 
	for (int i = 2; i <= sqrt(N); i++) {
		if (A[i] == 0) 
			continue;
		 
		for (int j = i + i; j <= N; j += i) {
			A[j] = 0; 
		}
	}
	 

	for (int i = M; i <= N; i++) {
		if (A[i] != 0) 
			cout << A[i] << "\n";
	}
	


}
