#include<iostream>
#include<vector>
using namespace std;

class minHeap
{
public:
	void push(int n)
	{
		v.push_back(n);

		int curr = v.size() - 1;
		int parent = (curr - 1) / 2;

		while (parent >= 0)
		{
			if (abs(v[curr]) >= abs(v[parent]))
				break;

			{ // 데이터 교환
				int temp = v[curr];
				v[curr] = v[parent];
				v[parent] = temp;
			}

			curr = parent;
			parent = (curr - 1) / 2;
		}
	}

	void pop()
	{
		if (v.empty()) return;

		int end = v.size() - 1;
		v[0] = v[end--];
		v.pop_back();

		int curr = 0;
		int lChild = curr * 2 + 1;
		int rChild = lChild + 1;
		int minChild;

		while (lChild <= end)
		{
			if (rChild > end || abs(v[lChild]) < abs(v[rChild]))
				minChild = lChild;
			else minChild = rChild;

			if (abs(v[curr]) <= abs(v[minChild]))
				break;

			{
				int temp = v[curr];
				v[curr] = v[minChild];
				v[minChild] = temp;

				curr = minChild;
				lChild = curr * 2 + 1;
				rChild = lChild + 1;
			}
		}
	}

	int top()
	{
		if (v.empty()) return INT32_MAX;
		return v.front();
	}

	bool empty() { return v.empty(); }

private:
	vector<int> v;
};

int main()
{
	int N, x;
	cin >> N;
	vector<int> result;

	minHeap mh;
	minHeap nMh;
	while (N--)
	{

		cin >> x;
		if (x == 0)
		{
			if (mh.empty() && nMh.empty())
			{
				result.push_back(0);
				continue;
			}

			minHeap* temp;
			if (mh.top() < abs(nMh.top()))
				temp = &mh;
			else
				temp = &nMh;

			result.push_back(temp->top());
			temp->pop();

		}
		else
		{
			if (x > 0)
				mh.push(x);
			else
				nMh.push(x);

		}

	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
}