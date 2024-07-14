#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct map
{
        map(int size = 1000000)
        {
                table.resize(size);
        }

        int GetHash(string str)
        {
                int ret = 1;
                for (int i = 0; i < str.size(); i++)
                {
                        ret += str[i] * (i + 1);
                        ret %= table.size();
                }
                return ret;
        }



        void insert(string key, int idx)
        {
                int k = GetHash(key);
                table[k].push_back({ key, idx });
        }

        int GetValue(string key)
        {
                int k = GetHash(key);

                for (auto& v : table[k])
                {
                        if (v.first == key)
                        {
                                return v.second;
                        }
                }

                return -1;
        }

        vector<vector<pair<string, int>>> table;
};

// 이름, 트리, (판매자, 판매개수)
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> sellers, vector<int> amounts) {

        map _map;
        vector<int> parents(enroll.size(), -1);

        for (int i = 0; i < enroll.size(); i++)
                _map.insert(enroll[i], i);

        for (int i = 0; i < referral.size(); i++)
        {
                if (referral[i] == "-")
                        continue;

                int parent = _map.GetValue(referral[i]);
                parents[i] = parent;
        }

        vector<int> answer(enroll.size());
        for (int i = 0; i < sellers.size(); i++)
        {
                int seller = _map.GetValue(sellers[i]);
                int amount = amounts[i] * 100;

                while (seller >= 0)
                {
                        int profit = amount;
                        if (amount >= 10)
                        {
                                // 12 의 10% == 1

                                profit = amount - (amount / 10);
                        }

                        // cout << seller << ", " << amount <<" - " <<profit << "\n";

                        answer[seller] += profit;
                        amount -= profit;
                        seller = parents[seller];
                }

        }

        return answer;
}

// string에 index를 부여하는게 핵심 문제
