#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, temp;
	cin >> N >> M;

	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			v[i][j] = v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1] + temp;
		}
	}
	

	for (int i = 1; i <= M; i++)
	{
		int aX, aY, bX, bY;
		cin >> aX >> aY >> bX >> bY;

		cout << v[bX][bY] - v[aX - 1][bY] - v[bX][aY - 1] + v[aX - 1][aY - 1] << "\n";
		
	}



	return 0;
}