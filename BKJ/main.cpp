#include<algorithm>

using namespace std;

int GetCost(int num)
{
        if (num < 10)
                return min(num, 10 - num + 1);

        int A = num % 10;
        int B = 10 - num % 10;

        return min(GetCost((num - A) / 10) + A, GetCost((num + B) / 10) + B);
}

int solution(int storey)
{

        return GetCost(storey);
}