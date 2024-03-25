#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int N, M;
	cin >> N;
	cin >> M;
	vector<int> lessons(N);
	
	int start = 0;
	int end = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> lessons[i];
		if (start < lessons[i])
			start = lessons[i];
		end += lessons[i];
	}
	 
	while (start <= end)
	{
		int middie = (start + end) / 2;
		int sum = 0;
		int count = 0;

		for (int i = 0; i < N; i++)
		{
			if (sum + lessons[i] > middie)
			{
				count++;
				sum = 0;
			}
			sum += lessons[i];
		}
		if (sum != 0)
			count++;
		if (count > M)
			start = middie + 1;
		else
			end = middie - 1;
	 }
	cout << start << "\n"; 
}
 
