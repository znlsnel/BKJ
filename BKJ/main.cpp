#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {


        map<int, int> t;
        for (int n : tangerine)
                t[n]++;

        vector<pair<int, int>> v;
        for (auto p : t)
                v.push_back(p);

        sort(v.begin(), v.end(),
                [](pair<int, int> a, pair<int, int> b) {return a.second > b.second; });

        int answer = 0;
        int total = 0;
        for (auto p : v)
        {
                total += p.second;
                answer++;
                if (total >= k)
                        break;
        }

        return answer;
}


// 서로 다른 크기의 종류 최소화
// 1 3 2 5 4 5 2 3
// 정렬
// 1 2 2 3 3 4 5 5