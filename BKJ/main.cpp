#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {

        stack<int> s;
        int cur = 1;
        int answer = 0;

        for (int n : order)
        {
                if (n >= cur)
                {
                        while (n > cur)
                                s.push(cur++);
                        cur++;
                }

                else if (s.top() == n)
                        s.pop();

                else
                        break;

                answer++;
        }

        return answer;
}