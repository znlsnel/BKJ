#include <string>
#include <vector>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
        if (b == 0)
                return a;

        return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
        int gcdA = arrayA[0];
        int gcdB = arrayB[0];

        for (int n : arrayA)
                gcdA = gcd(gcdA, n);

        for (int n : arrayB)
                gcdB = gcd(gcdB, n);

        for (int i = 0; i < arrayA.size(); i++)
        {
                if (arrayA[i] % gcdB == 0)
                        gcdB = -1;
        }

        for (int i = 0; i < arrayB.size(); i++)
        {
                if (arrayB[i] % gcdA == 0)
                        gcdA = -1;
        }

        int answer = max(gcdA, gcdB);

        return max(answer, 0);
}