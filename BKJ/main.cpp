#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
        map<string, int> m;

        for (int i = 0; i < friends.size(); i++)
                m.insert(make_pair(friends[i], i));

        vector<vector<int>> v(friends.size(), vector<int>(friends.size()));


        for (string s : gifts)
        {
                string from;
                string to;

                bool findSpace = false;
                for (auto c : s)
                {
                        if (c == ' ')
                        {
                                findSpace = true;
                                continue;
                        }

                        if (findSpace)
                                to.push_back(c);

                        else
                                from.push_back(c);
                }
                auto a = m.find(from);
                auto b = m.find(to);

                int fromID = (*a).second;
                int toID = (*b).second;
                v[fromID][toID]++;
        }

        vector<int> result(v.size());
        for (int i = 0; i < v.size(); i++)
        {
                for (int j = i; j < v[i].size(); j++)
                {
                        // 내가 더 많이 줬다면 ~~
                        if (v[i][j] > 0 && v[i][j] > v[j][i])
                        {
                                result[i]++;
                        }
                        // 내가 더 많이 받았다면 ~~
                        else if (v[j][i] > 0 && v[i][j] < v[j][i])
                        {
                                result[j]++;
                        }

                        // 똑같이 받았다면 ~~ 선물 지수 체크
                        else if (v[i][j] == v[j][i])
                        {
                                int i_score = 0;
                                int j_score = 0;
                                for (int n = 0; n < v[i].size(); n++) {
                                        i_score += v[i][n];
                                        i_score -= v[n][i];
                                }

                                for (int n = 0; n < v[j].size(); n++) {
                                        j_score += v[j][n];
                                        j_score -= v[n][j];
                                }

                                if (i_score > j_score)
                                {
                                        result[i]++;
                                }
                                else if (i_score < j_score)
                                        result[j]++;
                        }
                }
        }


        int MAX = 0;
        for (int n : result)
                MAX = max(n, MAX);


        return MAX;
}