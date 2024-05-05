#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static vector<long> D;
  

// ⌈⌉
// ⌊⌋ , [ㅁㅁ]

// ⌈⌉ 
// ⌊⌋  1개
// 
// ⌈⌉⌈⌉  // [ㅡㅡ] 
// ⌊⌋⌊⌋  // [ㅡㅡ]  2개

// ⌈⌉⌈⌉⌈⌉   // ⌈⌉ [ㅡㅡ]     // [ㅡㅡ]⌈⌉
 //⌊⌋⌊⌋⌊⌋   // ⌊⌋ [ㅡㅡ]     // [ㅡㅡ]⌊⌋  3개

// ⌈⌉⌈⌉⌈⌉⌈⌉ // ⌈⌉⌈⌉[ㅡㅡ] //⌈⌉ [ㅡㅡ]⌈⌉ // [ㅡㅡ]⌈⌉⌈⌉ // [ㅡㅡ][ㅡㅡ]
// ⌊⌋⌊⌋⌊⌋⌊⌋ // ⌊⌋⌊⌋[ㅡㅡ] //⌊⌋ [ㅡㅡ]⌊⌋ // [ㅡㅡ]⌊⌋⌊⌋ // [ㅡㅡ][ㅡㅡ]  // 5개 

// 4의 경우의 수 = 3의 경우의 수 + 2의 경우의 수
// 3의 경우의 수 = 2의 경우의 수 + 1의 경우의 수

long Function(int id)
{
	if (D[id] > 0)
		return D[id];	
	 
	return D[id] = (Function(id - 1) + Function(id - 2) ) % 10007;  
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N; 

	D.resize(N + 1); 
	D[1] = 1;
	D[2] = 2; 

	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + D[i - 2]) % 10007;
	}
	 
	cout << D[N];  
}
 