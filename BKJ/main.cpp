#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> edge;

long MAXLONG = 20000000000;
long MINLONG = -2147483647;

int N, M, sCity, eCity;
static vector<long> mdistance, cityMoney;
static vector<edge> edges;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> sCity >> eCity >> M;
	mdistance.resize(N);
	cityMoney.resize(N);
	fill(mdistance.begin(), mdistance.end(), MINLONG);

	for (int i = 0; i < M; i++)
	{
		int start, end, price;
		cin >> start >> end >> price;
		edges.push_back(make_tuple(start, end, price));
	}
	for (int i = 0; i < N; i++)
	{
		cin >> cityMoney[i];
	}
	mdistance[sCity] = cityMoney[sCity];

	for (int i = 0; i <= N + 50; i++)
	{
		for (int j = 0; j < M; j++) {
			int start = get<0>(edges[j]);
			int end = get<1>(edges[j]);
			int price = get<2>(edges[j]);

			if (mdistance[start] == MINLONG) 
				continue;

			else if (mdistance[start] == MAXLONG) {
				mdistance[end] = MAXLONG;
			}

			else if (mdistance[end] < mdistance[start] + cityMoney[end] - price) {
				mdistance[end] = mdistance[start] + cityMoney[end] - price;
				if (i >= N - 1)
					mdistance[end] = MAXLONG;
			}
		}
		
	}
	if (mdistance[eCity] == MINLONG) 
		cout << "gg\n";
	else if (mdistance[eCity] == MAXLONG)
		cout << "Gee\n";
	else
		cout << mdistance[eCity] << "\n";
	 
	return 0;
}

