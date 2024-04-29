#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int D[1001]; 
double Total = 0;
int M, K;

// 색상 A 수 / 전체 수 -> 색상 A수 --; (연속 수 <= A 수) -> 반복

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;


	for (int i = 0; i < M; i++) {
		cin >> D[i];
		Total += D[i];
	}

	cin >> K;

	double result = 0.0f;
	for (int i = 0; i < M; i++) {

		if (D[i] < K)
			continue;

		double val = 1.0; 

		for (int j = 0; j < K; j++) {
			val *= double(D[i] - j) / (Total - j);
		} 
		 
		result += val;

	}
	 
	cout << fixed; 
	cout.precision(18);
	cout << result;
}

