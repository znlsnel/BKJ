#include <iostream>
#include <vector>

using namespace std;

int N, K;
bool a[10000];
vector<int> v;

void PrimeNumber()
{
	for (int i = 2; i <= N; i++)
		a[i] = true;

	for (int i = 2; i <= N; i++)
	{
		if (a[i] == false) continue;
		for (int j = i; j <= N; j += i)
		{
			if (a[j] == false) continue;
			a[j] = false;
			v.push_back(j);
		}
	}

	if (v.size() >= K) cout << v[K - 1];

}

int main()
{
	cin >> N >> K;
	PrimeNumber();
	return 0;
}

