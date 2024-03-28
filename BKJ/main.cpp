#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	 

		long Min, Max;
		cin >> Min >> Max;
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
		 
		int count = 0;
		for (int i = 2; i < 10000001; i++)
		{
			if (A[i] == 0) continue; 

			long temp = A[i];
			while ((double)A[i] <= (double)Max / (double)temp)
			{
				if (double(A[i] >= double(Min) / double(temp)))
					count++;
				temp = temp * A[i];  
			}
		} 

		cout << count << "\n";
	
}
