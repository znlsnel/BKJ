#include<iostream>
#include <deque>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		int now;
		cin >> now;
		
		// 정렬대신 도태된 노드들 삭제
		while (!q.empty() && q.back().first > now)
			q.pop_back();

		q.push_back(make_pair(now, i));

		if (q.front().second <= i - L)
			q.pop_front();

		cout << q.front().first << " ";
	}
	

}
