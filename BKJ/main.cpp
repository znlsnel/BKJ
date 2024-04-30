#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N, Q;
static long F[21], S[21];
static bool visited[21] = { false };

void answer1();
void answer2();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	F[0] = 1;
	for (int i = 1; i < N; i++) {
		F[i] = F[i - 1] * i;
	}

	if (Q == 1) {
		answer1();
	}
	else if (Q == 2) {
		answer2();
	}
}
void answer1() 
{
	long K;
	cin >> K; 

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1, cnt = 1; i <= N; j++)
		{
			if (visited[j])
				continue;

			if (K <= F[N - i] * cnt) {
				K -= F[N - i] * (cnt - 1);
				S[i] = j;
				visited[j] = true;
				break;
			}
			cnt++;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << S[i] << " ";
}
void answer2()
{
	long K = 1;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		int cnt = 0;
		for (int j = 1; j < S[i]; j++)
		{
			if (visited[j] == false)
				cnt++;
		}
		K += F[N - i] * cnt; 
		visited[S[i]] = true;
	}

	cout << K << "\n";
}

