#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
static vector<int> numList;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int N, M;
	cin >> N;
	numList.resize(N);
	for (int i = 0; i < N; i++)
		cin >> numList[i];

	sort(numList.begin(), numList.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int find = 0;
		int target;
		cin >> target;

		int start = 0;
		int end = numList.size() - 1;

		while (start <= end)
		{
			int midi = (start + end) / 2;
			int midV = numList[midi];

			if (midV > target)
				end = midi - 1;
			else if (midV < target)
				start = midi + 1; 
			else {
				find = 1;
				break;
			}
		}
		cout << find << "\n"; 
	}


}
 
