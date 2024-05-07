#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;
 
static int N;
static vector<int> A, L, R;

// 1일 때 = 9
// 2의 경우의 수 = 1의 경우의 수 * 2 - 1
// 3의 경우의 수 = 2의 경우의 수 * 2 - 1

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	cin >> N;
	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	L.resize(N);
	L[0] = A[0];
	int result = L[0];

	for (int i = 1; i < N; i++) {
		L[i] = max(A[i], L[i - 1] + A[i]);
		result = max(result, L[i]);
	}
	
	R.resize(N);
	R[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		R[i] = max(A[i], R[i + 1] + A[i]);
	}

	for (int i = 1; i < N - 1; i++) {
		int temp = L[i - 1] + R[i + 1];
		result = max(result, temp);
	}

	cout << result;
}