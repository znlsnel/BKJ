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
	 

	long N, K;
	cin >> N;
	cin >> K;
	vector<int> coins(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
	 
	int ans = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K  >= coins[i]) 
		{
			int count = K  / coins[i];
			ans += count;
			K -= count * coins[i];  
		}
	}

	cout << ans << "\n";
}
 
