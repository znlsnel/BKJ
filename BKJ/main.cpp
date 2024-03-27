#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<string> split(string example, char s);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int answer = 0;
	string example;
	cin >> example; 
	vector<string> str1 = split(example, '-');

	for (size_t i = 0; i < str1.size(); i++)
	{
		int n = 0;
		vector<string> str2 = split(str1[i], '+');
		for (size_t j = 0; j < str2.size(); j++)
		{
			for (size_t k = 0; k < str2[j].size(); k++)
			{ 
				n += (str2[j][k] - '0') * pow(10, str2[j].size() - 1 - k); 
			}
		} 
		if (i == 0)
			answer += n;
		else
			answer -= n;
	}
	cout << answer << "\n"; 
}
  
vector<string> split(string example, char s)
{
	vector<string> result; 
	
	string str;
	for (size_t i = 0; i < example.size(); i++)
	{
		if (example[i] != s)
			str.push_back(example[i]);
		else
		{
			result.push_back(str);
			str = "";
		}
	} 
	result.push_back(str);

	return result;
}
