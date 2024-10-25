#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
        map<tuple<int, int, int>, int> logs;

        for (auto& r : routes)
        {
                int time = 0;
                auto [y, x] = make_pair(points[r[0] - 1][0], points[r[0] - 1][1]);
                logs[{time, y, x}]++;

                for (int i = 1; i < r.size(); i++)
                {
                        auto [ry, rx] = make_pair(points[r[i] - 1][0], points[r[i] - 1][1]);

                        int dy = ry > y ? 1 : ry == y ? 0 : -1;
                        int dx = rx > x ? 1 : rx == x ? 0 : -1;

                        while (y != ry)
                        {
                                time++;
                                y += dy;
                                logs[{time, y, x}]++;
                        }

                        while (x != rx)
                        {
                                time++;
                                x += dx;
                                logs[{time, y, x}]++;
                        }
                }



        }

        int answer = 0;
        for (auto& log : logs)
        {
                //       cout << get<0>(log.first) << " : " <<  get<1>(log.first) << ", " << get<2>(log.first) << " -> " << log.second << "\n";
                if (log.second > 1)
                        answer++;
        }

        return answer;
}

// 같은 시간에 2개 이상의 로봇이 겹친 횟수를 구해야함
// 시간별로 위치를 기록
// 시간을 기준으로 오름차순 정렬
// 같은 시간에 같은 위치 2개 이상인 횟수 기록
// 100 * 100 * 100 => 최대 100만 (가능)