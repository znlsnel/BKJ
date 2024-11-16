#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 999999999;
void DFS(vector<string>& minerals, int dia, int iron, int stone, int cost = 0, int idx = 0)
{
        if (idx >= minerals.size() || dia + iron + stone == 0)
        {
                answer = min(answer, cost);
                return;
        }

        int left = min(int(minerals.size()) - idx, 5);

        // 다이아몬드 곡괭이를 사용할 때
        if (dia > 0)
                DFS(minerals, dia - 1, iron, stone, cost + left, idx + left);

        // 철 곡괭이를 사용할 때
        if (iron > 0)
        {
                int nxtCost = 0;
                for (int i = idx; i < idx + left; i++)
                {
                        if (minerals[i] == "diamond")
                                nxtCost += 5;
                        else
                                nxtCost += 1;
                }
                DFS(minerals, dia, iron - 1, stone, cost + nxtCost, idx + left);
        }


        // 돌 곡괭이 사용할 때
        if (stone > 0)
        {
                int nxtCost = 0;
                for (int i = idx; i < idx + left; i++)
                {
                        if (minerals[i] == "diamond")
                                nxtCost += 25;
                        else if (minerals[i] == "iron")
                                nxtCost += 5;
                        else
                                nxtCost += 1;
                }
                DFS(minerals, dia, iron, stone - 1, cost + nxtCost, idx + left);
        }

}

int solution(vector<int> picks, vector<string> minerals) {
        DFS(minerals, picks[0], picks[1], picks[2]);
        return answer;
}