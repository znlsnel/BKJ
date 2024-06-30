#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> scores) {
        int answer = 1;
        int a = scores[0][0];
        int b = scores[0][1];

        scores[0][0] = -10000;
        scores[0][1] = -10000;

        sort(scores.begin(), scores.end());
        vector<int> startIdxs;

        int start = scores[0][0];
        for (int i = 1; i < scores.size(); i++) {
                if (start != scores[i][0])
                {
                        start = scores[i][0];
                        startIdxs.push_back(i - 1);
                }
        }
        startIdxs.push_back(scores.size() - 1);

        for (int i = 1; i < scores.size(); i++)
        {
                int na = scores[i][0];
                int nb = scores[i][1];

                scores[i][0] = -1000;
                scores[i][1] = -1000;

                if (na > a && nb > b)
                        return -1;

                // na, nb와 모든 것을 비교하여 이동이 가능한지 비교
                // N^2 속도로 하면 불가능
                // logN * N으로 해결

                // 2,1  3,2  3,2  1,4
                // 두 수의 합으로 scores 정렬(N Log N)
                //  na + nb + 2 ~ 맨 뒤 탐색

                int cnt = 10000;
                bool flag = false;
                int s = startIdxs.back();
                for (int s = startIdxs.size() - 1; scores[startIdxs[s]][0] > na; s--, cnt--)
                {
                        if (scores[startIdxs[s]][1] > nb) {
                                flag = true;
                                break;
                        }
                        if (cnt == 0)
                                break;
                }
                if (flag)
                        continue;



                int nsum = na + nb;
                if (nsum > a + b)
                        answer++;
        }

        return answer;
}