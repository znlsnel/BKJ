#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> A(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());
	int Max = 0;

	for (int i = 0; i < N; i++)
	{
		if (Max < A[i].second - i)
			Max = A[i].second - i;
	}
	cout << Max + 1;
	return 0;
}