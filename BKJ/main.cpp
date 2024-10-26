#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> makeTable(string pattern)
{
	vector<int> table(pattern.size(), 0);

	// 0 0 1 2 0 1 2 
	// A B A B C A B

	// 0 0 0 
	// A B C D C D C
	int head = 0;
	for (int tail = 1; tail < pattern.size(); tail++)
	{
		while (head > 0 && pattern[head] != pattern[tail])
			head = table[head - 1];

		if (pattern[head] == pattern[tail])
		{
			table[tail] = ++head;
		}
	}

	return table;
}

void KMP(string str, string pattern)
{
	vector<int> table = makeTable(pattern);
	vector<int> pN;

	// A B A B A B C A B
	// A B A B C A B
	// 0 0 1 2 0 1 2

	int P = 0;
	for (int S = 0; S < str.size(); S++)
	{
		while (P > 0 && pattern[P] != str[S])
			P = table[P - 1];

		if (pattern[P] == str[S])
		{
			if (P == pattern.size() - 1)
			{
				pN.push_back(S - pattern.size() + 2);
				P = table[P];
			}
			else
				++P;
		}
	}

	cout << pN.size() << '\n';
	for (int i = 0; i < pN.size(); i++)
		cout << pN[i] << '\n';
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