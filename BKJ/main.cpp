#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
        vector<vector<int>> v(n, vector<int>(n, 0));

        for (auto& result : results)
        {
                v[result[0] - 1][result[1] - 1] = 1;
                v[result[1] - 1][result[0] - 1] = -1;
        }

        for (int k = 0; k < n; k++)
        {
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < n; j++)
                        {
                                if (v[i][k] != 0 && v[i][k] == v[k][j])
                                        v[i][j] = v[i][k];
                        }
                }
        }

        int answer = 0;
        for (int i = 0; i < n; i++)
        {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                        if (v[i][j] == 0)
                                cnt++;
                }
                if (cnt == 1)
                        answer++;
        }

        return answer;
}

// 4 3 1 [2 5]   
// 4는 3보다 쎄지만 4-1, 3-1은 결과는 없기 때문에 순위 매길 수 없음

// 길찾기가 가능한지 체크하면 되는거였음
// 4->3, 3->2, 1->2, 2->5
// 
// 
