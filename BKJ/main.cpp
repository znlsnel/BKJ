#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {

        long long start = 0;
        long long end = 10e16;
        long long answer = end;


        while (start <= end)
        {
                long long mid = (start + end) / 2;
                long long gold = 0, silver = 0, weight = 0;

                for (int i = 0; i < g.size(); i++)
                {
                        long long cnt = (mid + t[i]) / (t[i] * 2);
                        gold += min((long long)g[i], (long long)w[i] * cnt);
                        silver += min((long long)s[i], (long long)w[i] * cnt);
                        weight += min((long long)g[i] + s[i], (long long)w[i] * cnt);
                }
                if (weight >= a + b && gold >= a && silver >= b)
                {
                        answer = min(answer, mid);
                        end = mid - 1;
                }
                else
                        start = mid + 1;

        }
        return answer;
}