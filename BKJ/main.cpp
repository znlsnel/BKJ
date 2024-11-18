#include <string>
#include <vector>

using namespace std;

bool CHECK(vector<string>& places, vector<pair<int, int>>& P)
{
        for (int i = 0; i < P.size(); i++)
        {
                for (int j = i + 1; j < P.size(); j++)
                {
                        auto& [cy, cx] = P[i];
                        auto& [ty, tx] = P[j];

                        int dist = abs(cy - ty) + abs(cx - tx);
                        if (dist == 1)
                                return false;

                        if (dist == 2)
                        {
                                if (cy == ty && cx != tx && places[cy][(cx + tx) / 2] != 'X')
                                        return false;
                                if (cx == tx && cy != ty && places[(cy + ty) / 2][cx] != 'X')
                                        return false;
                                if (cy != ty && cx != tx)
                                {
                                        if (places[cy][tx] != 'X' || places[ty][cx] != 'X')
                                                return false;
                                }
                        }
                }
        }

        return true;
}

vector<int> solution(vector<vector<string>> places) {
        vector<int> answer(places.size());

        vector<vector<pair<int, int>>> PPos(places.size(), vector<pair<int, int>>());
        for (int N = 0; N < places.size(); N++)
        {
                auto& place = places[N];
                for (int i = 0; i < place.size(); i++)
                        for (int j = 0; j < place[i].size(); j++)
                                if (place[i][j] == 'P')
                                        PPos[N].push_back({ i, j });
        }

        for (int i = 0; i < PPos.size(); i++)
                answer[i] = CHECK(places[i], PPos[i]) ? 1 : 0;


        return answer;
}

// POOOP
// OXXOX
// OPXPX
// OOXOX
// POXXP