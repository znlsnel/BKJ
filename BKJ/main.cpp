#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	string str;
	cin >> str;
	
	for (int i = 0; i < str.size(); i++)
		v.push_back(str[i] - '0');

	for (int i = 0; i < v.size() - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[max] < v[j]) max = j;
		}
		if (max == i) continue;

		int temp = v[max];
		v[max] = v[i];
		v[i] = temp;
		
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	return 0;
}