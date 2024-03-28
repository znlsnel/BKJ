#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
using namespace std;


int gcd(int a, int b);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	 
	// 2 3 5 6 7 8 10
	long n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		int result = gcd(a, b);
		cout << a * b / result << "\n";
	}
	
}
 
int gcd(int a, int b)
{
	while (b != 0)
	{
		int k = a % b;
		a = b;
		b = k; 
	}
	return a;
}