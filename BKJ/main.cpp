#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {

        priority_queue<int> q;

        int r = 0;
        for (; r < enemy.size(); r++)
        {
                q.push(enemy[r]);
                n -= enemy[r];

                while (!q.empty() && n < 0 && k > 0)
                {
                        n += q.top();
                        k--;
                        q.pop();
                }

                if (n < 0)
                        break;
        }


        return r;
}