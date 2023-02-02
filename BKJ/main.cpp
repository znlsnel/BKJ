#include<iostream>
using namespace std;

int Arr[4];
int checkArr[4];
int checkSecret = 0;

void Add(char c);
void Remove(char c);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	
	string A;

	cin >> S >> P;
	cin >> A;

	for (int i = 0; i < 4; i++)
	{
		cin >> checkArr[i];
		if (checkArr[i] == 0)
			checkSecret++;
	}

	for (int i = 0; i < P; i++)
		Add(A[i]);

	int result = 0;

	if (checkSecret == 4)
		result++;

	for (int i = P; i < S; i++)
	{
		int j = i - P;
		Add(A[i]);
		Remove(A[j]);

		if (checkSecret == 4)
			result++;
	}
	cout << result;
}

void Add(char c)
{
	switch (c)
	{
	case 'A':
		Arr[0]++;
		if (Arr[0] == checkArr[0])
			checkSecret++;
		break;

	case 'C':
		Arr[1]++;
		if (Arr[1] == checkArr[1])
			checkSecret++;
		break;
	case 'G':
		Arr[2]++;
		if (Arr[2] == checkArr[2])
			checkSecret++;
		break;
	case 'T':
		Arr[3]++;
		if (Arr[3] == checkArr[3])
			checkSecret++;
		break;
	}
}

void Remove(char c)
{
	switch (c)
	{
	case 'A':
		if (Arr[0] == checkArr[0])
			checkSecret--;
		Arr[0]--;
		break;

	case 'C':
		if (Arr[1] == checkArr[1])
			checkSecret--;
		Arr[1]--;
		break;
	case 'G':
		if (Arr[2] == checkArr[2])
			checkSecret--;
		Arr[2]--;
		break;
	case 'T':
		if (Arr[3] == checkArr[3])
			checkSecret--;
		Arr[3]--;
		break;
	}
}