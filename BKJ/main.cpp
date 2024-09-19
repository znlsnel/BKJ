#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {

        long long answer = 0;

        sort(times.begin(), times.end());
        long long start = 1;
        long long end = (long long)times.back() * n;

        while (start <= end)
        {
                long long mid = (start + end) / 2;

                long long cnt = 0;
                for (int time : times)
                        cnt += mid / (long long)time;

                if (cnt < n)
                        start = mid + 1;
                else {
                        end = mid - 1;
                }
        }

        return end + 1;
}

// 