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
		long Min, Max;
		cin >> Min >> Max;
		// 2 - 10
		vector<bool> Check(Max - Min + 1);
		 
		for (long i = 2; i * i <= Max; i++)
		{
			long pow = i * i; // 4
			long start_index = Min / pow; // 0

			if (Min % pow != 0)
				start_index++;

			for (long j = start_index; pow * j <= Max; j++)
				Check[int(j * pow - Min)] = true;
		}

		int count = 0;
		for (int i = 0; i <= Max - Min; i++)
		{
			if (!Check[i])
				count++;
		}
		cout << count << "\n"; 
}