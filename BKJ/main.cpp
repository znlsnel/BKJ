#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> makeTable(string pattern)
{
	vector<int> table(pattern.size(), 0);

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

int main()
{
	int size;
	string pattern;

	cin >> size;
	cin >> pattern;

	vector<int> table = makeTable(pattern);
	cout << size - table[size - 1];

	return 0;
}