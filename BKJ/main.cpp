#include <iostream>
#include <vector>
#include <string>

using namespace std;

int KMP(string str)
{
	vector<int> table(str.size());
	for (int head = 0, tail = 1; tail < str.size(); tail++)
	{
		while (head > 0 && str[head] != str[tail])
			head = table[head - 1];

		if (str[head] == str[tail])
			table[tail] = ++head;
	}

	int MAX = 0;
	for (int i = 0; i < str.size(); i++)
		if (MAX < table[i]) MAX = table[i];

	return MAX;
}

int main()
{
	string str;
	cin >> str;

	int MAX = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int n = KMP(str.substr(i, str.size() - i));
		if (MAX < n) MAX = n;
	}
	cout << MAX;
	return 0;
}