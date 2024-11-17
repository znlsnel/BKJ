#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
        int answer = 0;

        for (auto& b : board)
                for (int& n : b)
                        answer = n == 1 ? 1 : n;


        for (int i = 1; i < board.size(); i++)
        {
                for (int j = 1; j < board[i].size(); j++)
                {
                        if (board[i][j] == 0)
                                continue;

                        int left = board[i][j - 1];
                        int up = board[i - 1][j];
                        int dia = board[i - 1][j - 1];

                        board[i][j] = min(left, min(up, dia)) + 1;
                        answer = max(answer, board[i][j] * board[i][j]);
                }

        }



        return answer;
}