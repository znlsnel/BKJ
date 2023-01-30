#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, temp;
	cin >> N >> M;

	int Aarr[100001] = {};
	
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		Aarr[i] = temp + Aarr[i - 1];
	}
	

	for (int i = 1; i <= M; i++)
	{
		int a, b, result;
		cin >> a >> b;
		cout << Aarr[b] - Aarr[a - 1] << "\n";
	}



	return 0;
}