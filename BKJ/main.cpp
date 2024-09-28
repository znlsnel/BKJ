#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {

        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        right[0][1] = 1;
        down[1][0] = 1;


        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        if (city_map[i][j] == 1)
                                continue;

                        else if (city_map[i][j] == 2)
                        {
                                if (i < m - 1 && i > 0)
                                        down[i + 1][j] = down[i][j] % MOD;

                                if (j < n - 1 && j > 0)
                                        right[i][j + 1] += right[i][j] % MOD;
                        }
                        else
                        {
                                if (i < m - 1)
                                        down[i + 1][j] += (down[i][j] + right[i][j]) % MOD;

                                if (j < n - 1)
                                        right[i][j + 1] += (down[i][j] + right[i][j]) % MOD;
                        }
                }
        }

        return (right[m - 1][n - 1] + down[m - 1][n - 1]) % MOD;
}

// 0 = 통행가능
// 1 = 동행불가능
// 2 = 직진만 가능