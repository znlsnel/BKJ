#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

struct MAP
{
        MAP(int size = 1000000)
        {
                table.resize(size);
        }

        int Hash(string str)
        {
                int ret = 1;
                for (char& c : str)
                {
                        ret *= c - 'A';
                        ret %= table.size();
                }
                return ret;
        }

        bool Insert(string key, int value)
        {
                int hash = Hash(key);
                for (auto& t : table[hash])
                {
                        if (t.first == key)
                                return false;
                }

                table[hash].push_back({ key, value });
                return true;
        }

        int GetValue(string key)
        {
                int hash = Hash(key);
                for (auto& t : table[hash])
                {
                        if (t.first == key)
                                return t.second;
                }

                return -1;
        }

        vector<vector<pair<string, int>>> table;
};

vector<int> solution(vector<string> gems) {

        MAP map;
        int gemCnt = 0;
        for (string& str : gems)
        {
                if (map.Insert(str, gemCnt))
                        gemCnt++;
        }
        vector<int> haveGem(gemCnt);
        vector<bool> foundGem(gemCnt);

        int foundGemCnt = 0;
        int s = 0;
        int e = 0;

        for (int i = 0; i < gems.size(); i++)
        {
                if (foundGemCnt >= gemCnt)
                        break;

                int idx = map.GetValue(gems[i]);
                haveGem[idx]++;

                if (!foundGem[idx])
                {
                        foundGem[idx] = true;
                        foundGemCnt++;
                }
                e = i;
        }
        vector<int> answer{ s, e };

        for (int i = e + 1; i < gems.size(); i++)
        {
                string& gem = gems[i];

                int sidx = map.GetValue(gems[s]);
                while (haveGem[sidx] > 1)
                {
                        haveGem[sidx]--;
                        s++;
                        sidx = map.GetValue(gems[s]);
                }

                if (answer[1] - answer[0] > e - s)
                {
                        answer[0] = s;
                        answer[1] = e;
                }

                int idx = map.GetValue(gem);
                haveGem[idx]++;
                e = i;
        }

        return { answer[0] + 1, answer[1] + 1 };
}