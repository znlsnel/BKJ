#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> edge;

long MAXLONG = 20000000000;

int N, M;
static vector<long> mdistance;
static vector<edge> edges;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	mdistance.resize(N + 1);
	std::fill(mdistance.begin(), mdistance.end(), MAXLONG);

	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		edges.push_back(make_tuple(start, end, time)); 
	} 
	mdistance[1] = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			edge medge = edges[j];
			int start = get<0>(medge);
			int end = get<1>(medge);
			int time = get<2>(medge);

			if (mdistance[start] != MAXLONG && mdistance[end] > mdistance[start] + time)
				mdistance[end] = mdistance[start] + time;
		}
	}

	bool mCycle = false;
	for (int i = 0; i < M; i++)
	{
		edge medge = edges[i];
		int start = get<0>(medge);
		int end = get<1>(medge);
		int time = get<2>(medge);

		if (mdistance[start] != MAXLONG && mdistance[end] > mdistance[start] + time)
			mCycle = true;
	}

	if (!mCycle)
	{
		for (int i = 2; i <= N; i++)
		{
			if (mdistance[i] == MAXLONG)
			{
				cout << -1 << "\n";
			}
			else {
				cout << mdistance[i] << "\n";
			}
		}
	}
	else
		cout << -1 << "\n";

	return 0;
}

