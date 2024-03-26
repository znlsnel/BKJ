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
	priority_queue<int, vector<int>> p_pq;
	priority_queue<int, vector<int>, greater<int>> n_pq;
	int data;
	int zeroCount = 0;
	int oneCount = 0;
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> data;
		if (data > 1)
			p_pq.push(data);
		else if (data == 0)
			zeroCount++;
		else if (data == 1)
			oneCount++;
		else 
			n_pq.push(data); 
	}

	int data1 = 0;
	int data2 = 0;

	while (p_pq.size() > 1)
	{
		data1 = p_pq.top();
		p_pq.pop();
		data2 = p_pq.top();
		p_pq.pop();
		sum += data1 * data2;
	}   
	if (p_pq.size()) {
		sum += p_pq.top();
		p_pq.pop();
	}

	while (n_pq.size() > 1)
	{
		data1 = n_pq.top();
		n_pq.pop();
		data2 = n_pq.top();
		n_pq.pop();
		sum += data1 * data2;
	} 
	if (n_pq.size()) {
		if (zeroCount == 0)
		{
			sum += n_pq.top();
			n_pq.pop(); 

		}
	}
	 

	sum += oneCount;
	cout << sum << "\n";

}
 
