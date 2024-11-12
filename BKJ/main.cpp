#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

void FIND(vector<vector<int>>& answer, int size, int max, int idx = 0, vector<int> v = vector<int>())
{
        if (v.size() == size)
        {
                answer.push_back(v);
                return;
        }


        if (idx > max - (size - v.size()))
                return;

        for (int i = idx; i < max; i++)
        {
                v.push_back(i);
                FIND(answer, size, max, i + 1, v);
                v.pop_back();
        }
}

bool CheckDuplicateKey(set<string>& keys, vector<int>& idxs)
{
        for (int i = 1; i <= idxs.size(); i++)
        {
                vector<vector<int>> a;
                FIND(a, i, idxs.size());

                for (auto& v : a)
                {
                        string key = "";
                        for (int& n : v)
                                key += to_string(idxs[n]);

                        if (keys.find(key) != keys.end())
                                return true;
                }
        }

        return false;
}


int solution(vector<vector<string>> relation) {
        int answer = 0;
        int size = relation[0].size();

        set<string> keys;

        for (int i = 1; i <= size; i++)
        {
                vector<vector<int>> a;
                FIND(a, i, size);

                int cnt = 1;
                for (auto& v : a)
                {
                        if (CheckDuplicateKey(keys, v))
                                continue;

                        bool flag = true;
                        set<string> s;

                        //  cout << "========== " << cnt++ << " ========\n";
                        for (int i = 0; i < relation.size(); i++)
                        {
                                string str = "";
                                for (int& idx : v)
                                        str += relation[i][idx];

                                // cout << str << "\n";

                                if (s.find(str) == s.end())
                                        s.insert(str);
                                else
                                {
                                        //cout << "발견 중복 발견 중복\n";
                                        flag = false;
                                        break;
                                }

                        }
                        if (flag) {
                                string key = "";
                                for (int& idx : v)
                                        key += to_string(idx);
                                keys.insert(key);
                                answer++;
                        }
                }
        }
        return answer;
}

// 중복되는 튜플이 없는 속성 찾기

// 중복이 있는 속성 모아두기
// 중복이 있는 속성을 조합해보기
// 1 2 3 4 5 6 7 8의 속성이 있을 떄,

// 8자리 = 1개
// 7자리 = 8개
// 6자리 = 26개
// 5자리 = 10개
// 4자리 = 15개
// 3자리 = 6 5 4 3 2 1
// 2자리 = 26개

// 12, 13, 14, 15, 16, 17, 18
// 23, 24, 25, 26, 27, 28
// 34, 35, 36, 37, 38
// 45, 46, 47, 48
// 56, 57, 58
// 67, 68
// 78