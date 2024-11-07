#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stack>

using namespace std;

bool cmp(tuple<int, int, int> A, tuple<int, int, int> B)
{
        return get<0>(A) < get<0>(B);
}
vector<string> solution(vector<vector<string>> plans) {

        vector<tuple<int, int, int>> p;
        for (int i = 0; i < plans.size(); i++)
        {
                string st = plans[i][1];
                int start = st[4] - '0' + (st[3] - '0') * 10 + (st[1] - '0') * 60 + (st[0] - '0') * 600;
                p.push_back({ start, start + stoi(plans[i][2]), i });
        }
        sort(p.begin(), p.end(), cmp);

        vector<string> answer;
        stack<pair<int, int>> st;

        for (int i = 0; i < p.size() - 1; i++)
        {
                auto [s, e, i1] = p[i];
                auto [s2, e2, i2] = p[i + 1];
                int interval = s2 - e;

                if (e <= s2)
                {
                        answer.push_back(plans[i1][0]);

                        while (!st.empty() && interval > 0)
                        {
                                pair<int, int> t = st.top(); st.pop();
                                int temp = t.first;

                                t.first = max(0, temp - interval);
                                interval = max(0, interval - temp);

                                if (t.first > 0)
                                        st.push({ t.first, t.second });
                                else
                                        answer.push_back(plans[t.second][0]);
                        }
                }
                else
                        st.push({ e - s2, i1 });
        }
        answer.push_back(plans[get<2>(p.back())][0]);

        while (!st.empty())
        {
                answer.push_back(plans[st.top().second][0]);
                st.pop();
        }


        return answer;
}