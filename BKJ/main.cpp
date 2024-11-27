#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
        vector<int> answer;

        vector<vector<int>> table(100, vector<int>(100));
        for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                        table[i][j] = i * columns + j + 1;

        for (auto& querie : queries)
        {
                pair<int, int> start = { querie[0] - 1, querie[1] - 1 };
                pair<int, int> end = { querie[2] - 1, querie[3] - 1 };

                int value = 99999999;

                deque<int> dq;
                vector<pair<int, int>> pos;

                for (int i = start.second; i <= end.second; i++)
                {
                        dq.push_back(table[start.first][i]);
                        pos.push_back({ start.first, i });
                }

                for (int i = start.first + 1; i <= end.first; i++)
                {
                        dq.push_back(table[i][end.second]);
                        pos.push_back({ i, end.second });

                }

                for (int i = end.second - 1; i >= start.second; i--)
                {
                        dq.push_back(table[end.first][i]);
                        pos.push_back({ end.first, i });
                }


                for (int i = end.first - 1; i >= start.first + 1; i--)
                {
                        dq.push_back(table[i][start.second]);
                        pos.push_back({ i, start.second });
                }

                dq.push_front(dq.back());
                dq.pop_back();


                for (int i = 0; i < dq.size(); i++)
                {
                        table[pos[i].first][pos[i].second] = dq[i];
                        //     cout << dq[i] << " ";
                        value = min(value, dq[i]);
                }
                //     cout << "\n";
                start.first++;
                start.second++;

                end.first--;
                end.second--;

                answer.push_back(value);
        }


        return answer;
}