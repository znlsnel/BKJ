#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

bool isPalindrome(int target);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	 

		long N;
		cin >> N;
		long A[10000001];

		for (int i = 2; i < 10000001; i++)
			A[i] = i;
		 
		for (int i = 2; i <= sqrt(10000001); i++)
		{
			if (A[i] == 0)
				continue;

			for (int j = i + i; j < 10000001; j += i)
				A[j] = 0;
		} 
		 
		int i = N;
		while (true)
		{ 
			int id = i++;
			if (A[id] == 0)  continue;
			 
			if (isPalindrome(A[id]))
			{
				cout << id;
				return 0;
			}

		}
	
}

bool isPalindrome(int target)
{
	if (target == 101)
		target = 101;
	string str = to_string(target);
	int s = 0;
	int e = str.size() - 1;

	while (s < e)
	{
		if (str[s] != str[e])
			return false;
		s++;
		e--;
	}
	return true; 
}
