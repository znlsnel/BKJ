#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int Max(int A, int B)
{
        return A  > B  ? A  : B;
}

bool Cmp(int A, int B)
{
        return A  > B  ? true  : false;
}

int solution(vector<int> a)
{
        int answer  = -1;
        vector<int> Cnt(a.size() + 1, 0);

        for (int i  = 0; i  < a.size(); i++)
                Cnt[a[i]]++;

        for (int i  = 0; i  < Cnt.size(); i++)
        {
                if (Cnt[i] == 0)
                        continue;
                if (Cnt[i] <= answer)
                        continue;

                int Result  = 0;
                // 교집합 갯수 찾기
                for (int j  = 0; j  < a.size() - 1; j++)
                {
                        if (a[j] != i  && a[j  + 1] != i)
                                continue;
                        if (a[j] == a[j  + 1])
                                continue;
                        Result++;
                        j++;
                }

                answer  = Max(answer, Result);
        }

        return answer  * 2;
}