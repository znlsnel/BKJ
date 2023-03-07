#include <iostream>
#include <vector>
using namespace std;

vector<int> MergeVector(vector<int> left, vector<int> right)
{
	vector<int> result;

	auto itL = left.begin();
	auto itR = right.begin();

	while (itL != left.end() && itR != right.end())
	{
		if (*itL < *itR)
			result.push_back(*itL++);
		else
			result.push_back(*itR++);
	}

	if (itL == left.end() && itR == right.end()) return result;

	if (itL == left.end())
	{
		for (; itR != right.end(); itR++)
			result.push_back(*itR);
	}

	else if (itR == right.end())
	{
		for (; itL != left.end(); itL++)
			result.push_back(*itL);
	}

	return result;

}

vector<int> MergeSort(vector<int> v)
{
	if (v.size() <= 1) return v;
	auto mid = v.begin();

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < v.size() / 2; i++)
		mid++;

	left.insert(left.end(), v.begin(), mid);
	left = MergeSort(left);
	
	right.insert(right.end(), mid, v.end());
	right = MergeSort(right);

	return MergeVector(left, right);
}

int main()
{
	
	int N;
	cin >> N;
	vector<int> v(N);


	for (int i = 0; i < N; i++)
		cin >> v[i];

	v = MergeSort(v);
	
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}