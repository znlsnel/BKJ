#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static long long D[101][10];

// 1일 때 = 9
// 2의 경우의 수 = 1의 경우의 수 * 2 - 1
// 3의 경우의 수 = 2의 경우의 수 * 2 - 1

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i < 10; i++)
		D[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][1];
		D[i][9] = D[i - 1][8];

		for (int j = 1; j <= 8; j++) {
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % 1000000000;
		}
	}

	long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + D[N][i]) % 1000000000;
	}

	cout << sum;
}