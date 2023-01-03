#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> makeTable(string str)
{
	vector<int> table(str.size());
	for (int head = 0, tail = 1; tail < str.size(); tail++)
	{
		while (head > 0 && str[head] != str[tail])
			head = table[head - 1];

		if (str[head] == str[tail])
			table[tail] = ++head;
	}
	return table;
}

void KMP(string str, string pattern)
{
	vector<int> table = makeTable(pattern);
	vector<bool> ptrN(str.size());
	int N = 0;

	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		while (j > 0 && pattern[j] != str[i])
			j = table[j - 1];

		if (pattern[j] == str[i])
		{
			if (j == pattern.size() - 1)
			{
				N++;
				ptrN[i - pattern.size() + 1] = true;
				j = table[j];
				// 21 - (7 - 1 ) = 15
			}
			else
				++j;
		}
	}
	cout << N << '\n';
	for (int i = 0; i < ptrN.size(); i++)
	{
		if (ptrN[i] == true)
			cout << i  + 1 << '\n';
	}

	
}

int main()
{
	string str;
	string pattern;

	getline(cin, str);
	getline(cin, pattern);

	KMP(str, pattern);
	
	
	return 0;
}