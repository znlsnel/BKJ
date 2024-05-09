#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;
 
static int D[1001][1001];
static int A, B;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	 
	cin >> A >> B;
	int result = 0;

	for (int i = 1; i <= A; i++)
	{
		string t;
		cin >> t;

		for (int j = 1; j <= B; j++) 
		{
			D[i][j] = int(t[j -1] - '0'); 

			if (D[i][j] == 1) {
				D[i][j] = min(D[i - 1][j], min(D[i][j - 1], D[i - 1][j - 1])) + 1;  
			}
			result = max(result, D[i][j]);    
		}
	} 
	   
	cout << result * result; 
} 

 