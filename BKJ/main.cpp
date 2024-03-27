#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 

	long N;
	cin >> N; 
	vector<pair<int, int>> times(N);

	for (int i = 0; i < N; i++) {
		cin >> times[i].second;
		cin >> times[i].first;
	} 

	sort(times.begin(), times.end());

	int count = 0;
	int end = -1;

	for (int i = 0; i < N; i++)
	{
		if (times[i].second >= end) {
			end = times[i].first; 
			count++;
		}
	}
	cout << count << "\n"; 

}
 
