#include <iostream>
#include <algorithm>

using namespace std;
long long int arr[5000000];

int main() {
	// 입출력 속도를 놓여주기 위함
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N은 입력받을 수의 갯수, K는 정렬했을때 몇 번째 수인지
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cout << arr[K - 1];

	return 0;
}