#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void GetMenuCombi(vector<string>& result, string& order, int num, string str = "", int idx = 0)
{
        if (str.size() == num)
        {
                result.push_back(str);
                return;
        }

        for (int i = idx; i < order.size(); i++)
        {
                GetMenuCombi(result, order, num, str + order[i], i + 1);
        }

}

vector<string> solution(vector<string> orders, vector<int> course) {

        map<string, int> combiCnt;

        for (string order : orders)
        {
                sort(order.begin(), order.end());
                for (int n : course)
                {
                        vector<string> combis;
                        GetMenuCombi(combis, order, n);

                        for (string combi : combis)
                                combiCnt[combi]++;
                }
        }

        map<int, pair<int, vector<string>>> ans;
        for (auto c : combiCnt)
        {
                string str = c.first;
                int len = c.first.size();
                int cnt = c.second;

                if (cnt == 1)
                        continue;

                if (ans[len].first < cnt)
                {
                        ans[len].first = cnt;
                        ans[len].second.clear();
                }

                if (ans[len].first == cnt)
                        ans[len].second.push_back(str);
        }

        vector<string> answer;

        for (auto [len, p] : ans)
        {
                for (string str : p.second)
                        answer.push_back(str);
        }

        sort(answer.begin(), answer.end());
        return answer;
}


// orders.size <= 20
// course.size <= 10 (2 <= value <= 10)

// orders[idx] = 2;
// orders 1234 = 12 13 14 23 24 34

// orders[idx] = 3;
// orders 1234 = 123 124 14 23 24 34
