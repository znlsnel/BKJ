#include <string>
#include <vector>
#include <climits>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
        long long answer = LLONG_MAX;

        // 이분탐색 start, end 초기화 (걸리는 시간)
        long long start = 0;
        long long end = 10e5 * 2 * 2 * 10e9; // 도시 수 * 재화 수 * 왕복 * 재화량 

        // 이분탐색을 시행하면서
        while (start <= end) {

                long long mid = (start + end) / 2;
                long long gold = 0;
                long long silver = 0;
                long long weight = 0;

                for (int i = 0; i < g.size(); i++)
                {
                        long long cnt = (mid + t[i]) / (t[i] * 2);
                        gold += min(g[i] * 1LL, w[i] * cnt * 1LL);
                        silver += min(s[i] * 1LL, w[i] * cnt * 1LL);
                        weight += min(g[i] + s[i] * 1LL, w[i] * cnt * 1LL);
                }
                if (weight >= a + b && gold >= a && silver >= b)
                {
                        answer = min(answer, mid);
                        end = mid - 1;
                }
                else
                {
                        start = mid + 1;
                }
        }

        return answer;
}