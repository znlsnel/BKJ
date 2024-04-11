#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> edge;
long MAXLONG = 20000000000;

void myFunction();
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while (TC--)
		myFunction();

	return 0;
}

void myFunction()
{
	int N, M, W;
	cin >> N >> M >> W;
	 
	vector<edge> edges; 
	vector<int> mdistance(N + 1, MAXLONG);
	 
	for (int i = 0; i < M; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		edges.push_back(make_tuple(s, e, t));
		edges.push_back(make_tuple(e, s, t));
	}
	for (int i = 0; i < W; i++)
	{
		int s, e, t; 
		cin >> s >> e >> t; 
		edges.push_back(make_tuple(s, e, -t));

	}

	mdistance[1] = 0;

	for (int i = 1; i < N; i++)
	{
		for (size_t j = 0; j < edges.size(); j++)
		{
			int start = get<0>(edges[j]); 
			int end = get<1>(edges[j]);
			int cost = get<2>(edges[j]);

			if (mdistance[start] != MAXLONG &&  mdistance[end] > mdistance[start] + cost)
			{
				mdistance[end] = mdistance[start] + cost; 
			}
		}
	}
	  
	bool mCycle = false;
	for (size_t i = 0; i < edges.size(); i++)
	{
		int start = get<0>(edges[i]);
		int end = get<1>(edges[i]);
		int cost = get<2>(edges[i]); 

		if (mdistance[start] != MAXLONG && mdistance[end] > mdistance[start] + cost)
		{
			mCycle = true;
			break;
		}
	}
	if (mCycle)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}