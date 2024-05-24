#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

class UF
{
public:
	static int FindParent(int parent[], int n)
	{
		if (parent[n] == n) return n;
		return parent[n] = FindParent(parent, parent[n]);
	}

	static void UnionParent(int parent[], int a, int b)
	{
		a = FindParent(parent, a);
		b = FindParent(parent, b);
		if (a < b) parent[b] = a;
		else parent[a] = b;
	}

	static bool GetParent(int parent[], int a, int b)
	{
		if (FindParent(parent, a) == FindParent(parent, b)) return false;
		else return true;
	}
};

class Edge
{
public:
	Edge(int a, int b, float d) {
		Node[0] = a;
		Node[1] = b;
		distance = d;
	}
	bool operator < (Edge& edge)
	{
		return this->distance < edge.distance;
	}
public:
	int Node[2];
	float distance;
};
int main()
{
	vector<Edge> v;
	vector<pair<int, int>> pv;
	int parent[101]{ 0 };
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		float a, b;
		parent[i] = i;
		cin >> a >> b;
		pv.push_back(make_pair(a, b));
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			float dist = static_cast<float>(
				sqrt(pow(pv[j].first - pv[i].first, 2) +
					pow(pv[j].second - pv[i].second, 2)));
			v.push_back(Edge(i, j, dist));
		}
	}
	sort(v.begin(), v.end());

	float sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (UF::GetParent(parent, v[i].Node[0], v[i].Node[1]))
		{
			sum += v[i].distance;
			UF::UnionParent(parent, v[i].Node[0], v[i].Node[1]);
		}
	}


	cout << round(sum * 100) / 100;

	return 0;
}