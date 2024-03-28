#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
using namespace std;


long gcd(long a, long b);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	 
	// 2 3 5 6 7 8 10
	long n, m;
	cin >> n >> m;
	if (m > n) {
		long temp = m;
		m = n;
		n = temp; 
	}
		long result = gcd(n, m);
		
		while (result--)
			cout << 1;
	
		cout << "\n";

}
  
long gcd(long a, long b)
{
	while (b != 0) 
	{ 
		long k = a % b;
		a = b;
		b = k; 
	}
	return a;
}