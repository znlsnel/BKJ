#include<iostream>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int count = 1;
	int start = 1;
	int end = 1;
	int sum = 1;

	while (end != N)
	{
		if (sum == N)
			count++;

		if (sum > N)
		{
			sum -= start;
			start++;
		}
		else
		{
			end++;
			sum += end;
		}
	}
	cout << count << "\n";

}