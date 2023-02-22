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

	vector<int> v(N);
	vector<int> total(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 0; i < v.size(); i++)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[min] > v[j]) min = j;
		}

		int temp = v[min];
		v[min] = v[i];
		v[i] = temp;
		
		if (i == 0)
			total[i] = v[i];
		else 
			total[i] = total[i - 1] + v[i];
	}

	// 3 1 4 3 2
	// 3 4 8 11 13 
	int result = 0;

	for (int i = 0; i < v.size(); i++)
	{
		result = result + total[i];
	}

	

	cout << result;
	return 0;
}