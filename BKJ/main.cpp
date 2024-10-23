#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
        int size = friends.size();

        map<string, int> names;
        for (int i = 0; i < friends.size(); i++)
                names.insert({ friends[i], i });

        // logs[0][1] -> 0번이 1번에게 준 선물 개수
        // 선물 지수는 logs[0][1~n] - logs[1~n][0]

        vector<vector<int>> logs(size, vector<int>(size));
        for (string& gift : gifts)
        {
                string A, B;
                for (int i = 0; i < gift.size(); i++)
                {
                        if (gift[i] == ' ')
                        {
                                A = gift.substr(0, i);
                                B = gift.substr(i + 1, gift.size() - i);
                                break;
                        }
                }

                int a = names[A];
                int b = names[B];

                logs[a][b]++;
        }

        // 선물 지수 구하기
        vector<int> points(size);
        for (int i = 0; i < size; i++)
        {
                for (int j = 0; j < size; j++)
                {
                        points[i] += logs[i][j];
                        points[i] -= logs[j][i];
                }
        }

        vector<int> answer(size);
        for (int i = 0; i < size; i++)
        {
                // i와 0~N 까지 비교하여 선물을 받아야하는지 체크
                for (int j = i + 1; j < size; j++)
                {
                        if (i == j)
                                continue;

                        if (logs[i][j] > logs[j][i])
                                answer[i]++;

                        else if (logs[i][j] < logs[j][i])
                                answer[j]++;

                        else if (points[i] > points[j])
                                answer[i]++;

                        else if (points[i] < points[j])
                                answer[j]++;
                }
        }

        return *max_element(answer.begin(), answer.end());
}

// 두 사람이 선물을 주고 받았다면 -> 둘 중 더 많이 받은 사람이 다음달에 선물을 받음
// 주고 받은 수가 같다면 (0, 0 포함) -> 선물 지수가 더 작은 사람이 다음달에 선물 받음
// 선물 지수 -> 이번달에 준 선물 수 - 받은 선물 수

// 다음달에 가장 많은 선물 수 반환