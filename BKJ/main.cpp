#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> accumulate(n + 1, vector<int>(m + 1, 0));

        for (auto skill : skills)
        {
                int type = skill[0];
                int r1 = skill[1];
                int c1 = skill[2];
                int r2 = skill[3];
                int c2 = skill[4];
                int degree = skill[5];
                if (type == 1)
                        degree *= -1;

                accumulate[r1][c1] += degree;
                accumulate[r1][c2 + 1] -= degree;
                accumulate[r2 + 1][c1] -= degree;
                accumulate[r2 + 1][c2 + 1] += degree;
        }
        for (int i = 0; i < n; i++)
                for (int j = 1; j < m; j++)
                        accumulate[i][j] += accumulate[i][j - 1];

        for (int i = 1; i < n; i++)
                for (int j = 0; j < m; j++)
                        accumulate[i][j] += accumulate[i - 1][j];


        int answer = 0;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        board[i][j] += accumulate[i][j];
                        if (board[i][j] > 0) {
                                answer++;
                        }
                }
        }

        return answer;
}