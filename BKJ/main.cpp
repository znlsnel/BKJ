#include <iostream>
#include <vector>

using namespace std;

void merge_sort(int s, int e);
static vector<int> A;
static vector<int> tmp;
static long result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	result = 0;
	merge_sort(1, N);
	cout << result << "\n";
}

void merge_sort(int start, int end)
{
	if (end - start < 1) return;

	int mid = start + (end - start) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);

	for (int i = start; i <= end; i++)
		tmp[i] = A[i];

	int k = start;
	int index1 = start;
	int index2 = mid + 1;

	while (index1 <= mid && index2 <= end)
	{
		if (tmp[index1] > tmp[index2])
		{
			A[k] = tmp[index2];
			result += index2 - k;
			k++;
			index2++;
		}
		else
		{
			A[k] = tmp[index1];
			k++;
			index1++;
		}
	}
	while (index1 <= mid)
	{
		A[k] = tmp[index1];
		k++;
		index1++;
	}
	while (index2 <= end)
	{
		A[k] = tmp[index2];
		k++;
		index2++;
	}
}