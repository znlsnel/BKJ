#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>


using namespace std;
map<pair<int, pair<int, int>>, int> times;

void update(pair<int, pair<int, int>> key)
{
        if (times.find(key) != times.end())
                times[key]++;
        else
                times.insert({ key, 1 });
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
        // 시간, 좌표

        for (int i = 0; i < routes.size(); i++)
        {
                int time = 0;
                for (int j = 1; j < routes[i].size(); j++)
                {
                        int start = routes[i][j - 1] - 1;
                        int dest = routes[i][j] - 1;

                        int y = points[start][0];
                        int x = points[start][1];

                        int dirY = points[dest][0] - y > 0 ? 1 : -1;
                        int dirX = points[dest][1] - x > 0 ? 1 : -1;

                        if (j == 1) {
                                update({ time++, {y, x} });
                        }


                        while (y != points[dest][0])
                        {
                                y += dirY;
                                update({ time++, {y, x} });
                        }

                        while (x != points[dest][1])
                        {
                                x += dirX;
                                update({ time++, {y, x} });
                        }
                }
        }

        int answer = 0;
        for (auto& time : times)
        {
                int cnt = time.second;
                if (cnt > 1) {
                        answer++;
                }
        }

        return answer;
}
