#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit)
{
        sort(people.begin(), people.end());
        int answer = 0;
        int idx = 0;


        while (idx < people.size())
        {
                int back = people.back();
                people.pop_back();

                if (back + people[idx] <= limit)
                        idx++;

                answer++;
        }

        return answer;
}