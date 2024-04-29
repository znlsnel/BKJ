#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int D[1001][1001]; 

int array[5][5] = {
	{1, 0, 0, 0, 0}, // 0개 0 개 선택
	{1, 1, 0, 0, 0}, // 1개 0, 1개 선택
	{1, 2, 1, 0, 0}, // 2개 0, 1, 2개 선택
	{1, 3, 0, 1, 0}, // 3개 0, 1, 3개 선택
	{1, 4, 0, 0, 1}, // 4개 0, 1, 4개 선택
};

void result()
{
	int N, M;
	cin >> N >> M;
	 
	for (int i = 0; i <= M; i++) {
		D[i][1] = i; 
		D[i][0] = 1;
		D[i][i] = 1;  
	}

	for (int i = 3; i <= M; i++) 
	{
		for (int j = 2; j <= N; j++) 
		{
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j]; 
		}
	}
	 
	cout << D[M][N] << "\n";  
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		result();
	}


}

