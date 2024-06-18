#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> jobs) {

        auto compare = [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; };
        sort(jobs.begin(), jobs.end(), compare);

        priority_queue<pair<int, int>> pq;

        int answer = 0;
        int idx = 0;
        int jobsSize = jobs.size();
        int timer = 0;

        while (idx < jobsSize || !pq.empty())
        {
                while (idx < jobsSize && jobs[idx][0] <= timer)
                {
                        pq.push({ -(jobs[idx][1]), jobs[idx][0] });
                        idx++;
                }

                if (!pq.empty())
                {
                        answer += timer - pq.top().second + -(pq.top().first);
                        timer += -(pq.top().first);
                        //cout << pq.top().first << "\n";
                        pq.pop();
                }

                else
                {
                        timer = jobs[idx][0];
                }
        }







        return answer / jobsSize;
}


