#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
        int answer = 0;

        long total_q1 = 0, total_q2 = 0, goal = 0;
        int front_q1 = 0, front_q2 = 0;

        for (int n : queue1)
                total_q1 += n;
        for (int n : queue2)
                total_q2 += n;

        goal = (total_q1 + total_q2) / 2;

        int cnt = queue1.size() + queue2.size() + 10;
        while (total_q1 != total_q2 && cnt--)
        {
                if (total_q1 > total_q2)
                {
                        int value = queue1[front_q1];
                        queue2.push_back(value);
                        total_q2 += value;
                        total_q1 -= value;
                        front_q1++;
                }
                else
                {
                        int value = queue2[front_q2];
                        queue1.push_back(value);
                        total_q1 += value;
                        total_q2 -= value;
                        front_q2++;
                }

                answer++;
        }

        if (cnt <= 0)
                answer = -1;

        return answer;
}