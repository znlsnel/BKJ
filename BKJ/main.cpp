#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static vector<int> D;

// 10 -> 9
// 9 -> 3
//8 -> 4
// 7 -> 6
//6 -> 3
// 5 -> 4
// 4 -> 2 
// 3 -> 1
// 2 -> 1
// 1 -> 0


void result(int id)
{
	int nextDepth = D[id - 1] + 1;

	if (id % 3 == 0)
		nextDepth = min(D[id / 3] + 1, nextDepth);

	if (id % 2 == 0)
		nextDepth = min(D[id / 2] + 1, nextDepth);


	D[id] = nextDepth;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	D.resize(N + 1);

	D[1] = 0;
	D[2] = 1;
	D[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		result(i);
	}

	cout << D[N];
}
