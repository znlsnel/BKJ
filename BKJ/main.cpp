#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v;

void Solution()
{
	string str;
	stack<int> s;
	int id = 0;

	for (int i = 1; i <= v.size(); i++)
	{
		s.push(i);
		str.push_back('+');
		
		while (!s.empty() && v[id] == s.top())
		{
			s.pop();
			str.push_back('-');
			id++;
		}
	}

	if (!s.empty())
	{
		cout << "NO";
		return;
	}

	for (int i = 0; i < str.size(); i++)
		cout << str[i] << "\n";
	

}

int main()
{
	int N;
	cin >> N;
	v.resize(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	Solution();

	return 0;
}