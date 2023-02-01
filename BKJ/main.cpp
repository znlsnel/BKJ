#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> v(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	
	int i = 0;
	int j = N - 1;
	int sum;
	int count = 0;

	while (i < j)
	{
		sum = v[i] + v[j];

		if (sum < M) 
			i++;

		else if (sum > M) 
			j--;

		else
		{
			count++;
			i++;
		}
	}
	cout << count;
}