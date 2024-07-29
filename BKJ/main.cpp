#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {

        priority_queue<int> q;
        for (int& n : works)
                q.push(n);

        while (n--)
        {
                int maxN = q.top(); q.pop();
                q.push(maxN - 1);
        }

        long long answer = 0;
        while (!q.empty())
        {
                int n = q.top(); q.pop();
                if (n <= 0)
                        continue;

                answer += n * n;
        }

        return answer;
}