#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MaxScore;
vector<int> mine(11);
vector<int> answer{ -1 };

void DFS(vector<int>& info, int idx, int coin, int score, int op_score)
{
        // 이기던가 지던가 (비기면 안됨)
        if (idx == 11)
        {
                mine[10] += coin;
                if (score > op_score && MaxScore < (score - op_score))
                {
                        answer = mine;
                        MaxScore = score - op_score;
                }
                else if (score > op_score && MaxScore == (score - op_score))
                {
                        for (int i = 10; i >= 0; --i)
                        {
                                if (mine[i] > answer[i])
                                {
                                        answer = mine;
                                        break;
                                }
                                else if (mine[i] < answer[i])
                                        break;
                        }
                }
                return;
        }

        // 이길 경우
        if (info[idx] < coin)
        {
                mine[idx] = info[idx] + 1;
                DFS(info, idx + 1, coin - mine[idx], score + (10 - idx), op_score);

        }

        // 질 경우
        if (info[idx] > 0)
                op_score = op_score + (10 - idx);

        mine[idx] = 0;
        DFS(info, idx + 1, coin, score, op_score);
}

vector<int> solution(int n, vector<int> info) {
        DFS(info, 0, n, 0, 0);
        return answer;
}