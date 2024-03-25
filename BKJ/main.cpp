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
	long start = 1;
	long end = K; 
	long ans = 0;

	while (start <= end)
	{
		long mid = (start + end) / 2;
		int cnt = 0;

		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);

		if (cnt < K)
			start = mid + 1;
		else 
		{
			ans = mid;
			end = mid - 1;
		}

	}
	cout << ans << "\n"; 

}
 
