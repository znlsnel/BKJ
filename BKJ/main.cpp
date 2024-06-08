#include <vector>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
        int N = rc.size();
        int M = rc[0].size();
        deque<int> left_col, right_col;
        deque<int> rows[N];

        // Initialize the left and right columns and rows deque
        for (int i = 0; i < N; ++i)
        {
                left_col.push_back(rc[i][0]);
                right_col.push_back(rc[i][M - 1]);
        }

        for (int i = 0; i < N; i++)
        {
                for (int j = 1; j < M - 1; j++)
                        rows[i].push_back(rc[i][j]);
        }

        int idx = 0;
        for (const string& op : operations)
        {
                if (op == "ShiftRow")
                {
                        left_col.push_front(left_col.back());
                        left_col.pop_back();

                        right_col.push_front(right_col.back());
                        right_col.pop_back();

                        --idx;
                        if (idx < 0) idx = N - 1;
                }
                else
                { // Rotate
                        rows[idx].push_front(left_col.front());
                        left_col.pop_front();

                        right_col.push_front(rows[idx].back());
                        rows[idx].pop_back();

                        int backIdx = (idx + N - 1) % N;
                        rows[backIdx].push_back(right_col.back());
                        right_col.pop_back();

                        left_col.push_back(rows[backIdx].front());
                        rows[backIdx].pop_front();
                }
        }

        // Build the answer
        vector<vector<int>> answer(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
        {
                answer[i][0] = left_col[i];

                for (int j = 1; j < M - 1; ++j)
                {
                        answer[i][j] = rows[(i + idx) % N][j - 1];
                }

                answer[i][M - 1] = right_col[i];
        }

        return answer;
}