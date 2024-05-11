#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static long D[101][101][101];
static int N, L, R;
static int mod = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> L >> R;

	D[1][1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			for (int k = 1; k <= R; k++)
			{
				D[i][j][k] = D[i - 1][j - 1][k] + D[i - 1][j][k - 1] + D[i - 1][j][k] * (i - 2);
				D[i][j][k] %= mod;
			}
		}
	}

	cout << D[N][L][R];
}

