#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static vector<int> D;

void result(int i)
{
	
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N; 
	D.resize(N + 10, 0);
	 
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		int index = i + (a - 1);
		 
		if (D[index] < b)
			D[index] = b;



		 
	}  

	cout << D[N];
} 
 

//3 10 
//5 20 
//1 10 
//1 20 
//2 15 
//4 40 
//2 200
//
//->
//
//1
//2 
//3 10, 10
//4 20
//5 0
//6 15 , 20
//7 0
// 8 

