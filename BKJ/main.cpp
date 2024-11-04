#include <string>
#include <vector>

using namespace std;


int DFS(vector<pair<int, int>>& queens, int y, int n)
{

        if (queens.size() == n)
                return 1;

        int answer = 0;
        for (int x = 0; x < n; x++)
        {
                bool flag = true;
                for (auto& queen : queens)
                {
                        if (x == queen.second || y == queen.first ||
                                abs(x - queen.second) == abs(y - queen.first))
                        {
                                flag = false;
                                break;
                        }
                }

                if (flag)
                {
                        queens.push_back({ y, x });
                        answer += DFS(queens, y + 1, n);
                        queens.pop_back();
                }
        }

        return answer;
}

int solution(int n) {

        vector<pair<int, int>> queens;
        return DFS(queens, 0, n);

}