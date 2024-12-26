#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int GetCost(vector<string>& map, pair<int, int> start, pair<int, int> end)
{
        vector<vector<int>> cost(map.size(), vector<int>(map[0].size(),
                numeric_limits<int>::max()));

        priority_queue<pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>, greater<>> pq;

        cost[start.first][start.second] = 0;
        pq.push({ 0, start });

        while (!pq.empty())
        {
                auto [currentCost, info] = pq.top(); pq.pop();
                auto [cy, cx] = info;

                if (cy == end.first && cx == end.second)
                        return currentCost;

                for (int i = 0; i < 4; i++)
                {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];

                        if (ny < 0 || ny >= map.size() ||
                                nx < 0 || nx >= map[0].size() ||
                                map[ny][nx] == 'X')
                                continue;

                        int newCost = currentCost + 1;

                        if (newCost < cost[ny][nx])
                        {
                                cost[ny][nx] = newCost;
                                pq.push({ newCost, {ny, nx} });
                        }
                }
        }

        return -1; // 목표 지점에 도달할 수 없는 경우
}

int solution(vector<string> maps) {
        int answer = 0;

        pair<int, int> sPos, lPos, ePos;

        for (int i = 0; i < maps.size(); i++)
                for (int j = 0; j < maps[i].size(); j++) {

                        if (maps[i][j] == 'L')
                                lPos = make_pair(i, j);
                        else if (maps[i][j] == 'E')
                                ePos = make_pair(i, j);
                        else if (maps[i][j] == 'S')
                                sPos = make_pair(i, j);
                }

        int toL = GetCost(maps, sPos, lPos);
        int toE = GetCost(maps, lPos, ePos);
        return (toL == -1 || toE == -1) ? -1 : toL + toE;
}