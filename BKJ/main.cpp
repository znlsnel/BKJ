#include<iostream>
#include <queue>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<pair<int, int>> q;

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int result = 0;
		int a;
		cin >> a;

		q.push(make_pair(-a, i));
		pair<int, int> p = q.top();

		while (true)
		{
			int value = -p.first;
			int index = p.second;

			if (index > i - L)
			{
				result = value;
				break;
			}
			else
			{
				q.pop();
				p = q.top();
			}
		}

		cout << result << " ";
	}
	

}
