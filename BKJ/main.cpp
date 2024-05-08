#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;
 
static int N;
static int DP[1001][1001];
static string A, B;
static vector<char> Path;
void GetText(int r, int c);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	cin >> A >> B;
	for (int i = 1; i <= A.size(); i++)
	{
		for (int j = 1; j <= B.size(); j++)
		{
			if (A[i - 1] == B[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	} 
	cout << DP[A.size()][B.size()] << "\n";
	GetText(A.size(), B.size());
	 
	for (int i = Path.size() - 1; i >= 0; i--) {
		cout << Path[i]; 
	}
	cout << "\n";
}
  
void GetText(int r, int c)
{
	if (r == 0 || c == 0) {
		return;
	}

	if (A[r - 1] == B[c - 1]) {
		Path.push_back(A[r - 1]); 
		GetText(r - 1, c - 1);
	}
	else {
		if (DP[r - 1][c] > DP[r][c - 1])
			GetText(r - 1, c);
		else
			GetText(r, c - 1);
	}


}