#include <iostream>
#include <vector>
using namespace std;


enum MAXorMIN
{
	// PQ객체 생성시 읽기 편하게 enum으로 만들었음
	MIN = false,
	MAX = true
};

class PQ
{
public:
	PQ(bool b)
	{
		isMAX = b; // true로 하면 maxHeap
	}

	void push(int n)
	{
		v.push_back(n);
		// vector을 사용했지만 배열로 해도 전혀 무방

		int root = static_cast<int>(v.size()) - 1;
		int c = root;

		do
		{ // 부모노드와 비교 후 자리 바꿈
			root = max((c - 1) / 2, 0);
			int rN = v[root];
			int cN = v[c];

			// minHeap, maxHeap을 고려해서 비교함수를 만듦
			if (compare(rN, cN))
			{
				v[root] = cN;
				v[c] = rN;
			}

			c = root;
		} while (c > 0);
	}

	// minHeap과 maxHeap 사이에서 데이터 교환시 사용
	void exChange(int n)
	{
		if (v.size() == 0) return;

		int size = static_cast<int>(v.size()) - 1;

		v[0] = n;

		int c = 0;
		int root = 0;

		// 부모와 자식 비교 후 교환
		do
		{
			c = (root * 2) + 1;
			if (c > size) break;

			if (c < size && compare(v[c], v[c + 1]))
				c++;

			int rN = v[root];
			int cN = v[c];


			if (c <= size && compare(rN, cN))
			{
				v[root] = cN;
				v[c] = rN;
			}

			root = c;

		} while (root < size);


	}

	int top()
	{
		if ((int)v.size() == 0) return -1;
		return v[0];
	}

	bool compare(int r, int c)
	{
		if (isMAX) return r < c; // maxHeap은 큰게 위로
		return r > c; // minHeap은 작은게 위로
	}

	int size()
	{
		return static_cast<int>(v.size());
	}

	bool empty()
	{
		return static_cast<int>(v.size()) == 0;
	}

public:
	bool isMAX = false;
	vector<int> v;
};

int main()
{
	ios::sync_with_stdio(false); // 속도 빨라지는 코드
	cin.tie(NULL); // 속도 빨라지는 코드

	vector<int> v;
	int N, n;
	cin >> N;

	PQ max = PQ(MAX);
	PQ min = PQ(MIN);


	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);
	}



	for (int i = 0; i < N; i++)
	{
		n = v[i];

		if (max.size() == min.size())
			max.push(n); // 작은 값을 내림차순 정렬
		else
			min.push(n); // 큰 값을 오름차순 정렬
		// 그럼 maxHeap과 minHeap의 top값이 가운데 값이 됨

		if (!max.empty() && !min.empty() && max.top() > min.top())
		{
			int maxN, minN;
			maxN = max.top();
			minN = min.top();

			max.exChange(minN);
			min.exChange(maxN);
		}
		cout << max.top() << '\n';
	}

	return 0;
}