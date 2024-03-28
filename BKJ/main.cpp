#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	 
	// 2 3 5 6 7 8 10
	long n;
	cin >> n;
	long result = n;

	for (long p = 2; p <= sqrt(n); p++)
	{
		if (n % p == 0) {
			result -= result / p;
			while (n % p == 0)
				n /= p;
		}
	}

	if (n > 1)
		result -= result / n;

	cout << result << "\n"; 
}