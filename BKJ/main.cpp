#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int distance, vector<int> rocks, int n) {

        sort(rocks.begin(), rocks.end());

        int left = 0;
        int right = distance;
        int answer = 0;

        while (left <= right)
        {
                int mid = (left + right) / 2;
                int prev = 0;
                int remove_cnt = 0;

                for (int rock : rocks)
                {
                        if (rock - prev < mid)
                                remove_cnt++;
                        else
                                prev = rock;
                }
                if (distance - prev < mid)
                        remove_cnt++;

                if (remove_cnt <= n)
                {
                        answer = mid;
                        left = mid + 1;
                }
                else
                        right = mid - 1;

        }

        return answer;
}