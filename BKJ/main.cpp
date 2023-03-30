#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Is_Prime(int n)
{
	if (n < 2) return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}

	return true;
}

void Generate_numbers(int N, int digits, int current, vector<int>& result)
{
	if (N == digits)
	{
		result.push_back(current);
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		int next = current * 10 + i;
		if (Is_Prime(next))
			Generate_numbers(N, digits + 1, next, result);
	}
}

int main()
{
	vector<int> result;
	int N;
	cin >> N;
	
	Generate_numbers(N, 0, 0, result);
	sort(result.begin(), result.end());

	for (int i : result)
		cout << i << "\n";
	
	return 0;
}