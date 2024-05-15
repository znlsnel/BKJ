#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N, maxLength;
static int A[1000001];
static int B[1000001];
static int D[1000001];

int binarySearch(int left, int right, int cur);


int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        cin >> N;

        for (int i = 1; i <= N; i++)
                cin >> A[i];

        B[++maxLength] = A[1];
        D[1] = 1;

        for (int i = 2; i <= N; i++)
        {
                if (B[maxLength] < A[i])
                {
                        B[++maxLength] = A[i];
                        D[i] = maxLength;
                }
                else
                {
                        int index = binarySearch(1, maxLength, A[i]);
                        B[index] = A[i];
                        D[i] = index;
                }
        }

        cout << maxLength << "\n";

        vector<int> result(maxLength);
        for (int i = N; i > 0; i--)
        {
                if (D[i] == maxLength)
                {
                        --maxLength;
                        result[maxLength] = A[i];
                }
        }
        for (int i : result)
                cout << i << " ";

}

int binarySearch(int left, int right, int cur)
{
        int mid;

        while (left < right)
        {
                mid = (left + right) / 2;
                if (B[mid] < cur)
                        left = mid + 1;
                else
                        right = mid;
        }

        return left;
}