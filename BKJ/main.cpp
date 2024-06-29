#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> sq) {
        long long answer = 0;

        vector<int> v1(sq), v2(sq);
        vector<long long> dp1(sq.size(), 0), dp2(sq.size(), 0);
        long long max1 = 0, max2 = 0;

        for (int i = 0; i < sq.size(); i++)
        {
                if (i % 2 == 0)
                        v1[i] *= -1;
                else
                        v2[i] *= -1;

                if (i == 0) {
                        dp1[i] = v1[i];
                        dp2[i] = v2[i];
                        max1 = dp1[i];
                        max2 = dp2[i];
                        continue;

                }

                if (dp1[i - 1] + v1[i] > v1[i])
                        dp1[i] = dp1[i - 1] + v1[i];
                else
                        dp1[i] = v1[i];

                max1 = max(max1, dp1[i]);

                if (dp2[i - 1] + v2[i] > v2[i])
                        dp2[i] = dp2[i - 1] + v2[i];
                else
                        dp2[i] = v2[i];
                max2 = max(max2, dp2[i]);
        }
        return max(max1, max2);
}