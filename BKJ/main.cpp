#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
        vector<int> answer;
        while (left <= right)
        {
                int y = left / n;
                int x = left % n;
                answer.push_back(max(y, x) + 1);
                left++;
        }

        return answer;
}