#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n) {
        int answer = 0;

        queue<int> q;
        int total = 0;
        int num = 1;

        while (num <= n + 1)
        {
                if (total >= n)
                {
                        //      cout << "pop " + to_string(q.front()) << "\n";
                        total -= q.front();
                        q.pop();
                }
                else
                {
                        //     cout << "push " + to_string(num) << "\n";
                        total += num;
                        q.push(num++);
                }


                if (total == n)
                {
                        answer++;
                        //    cout << "찾았다\n\n";
                }

        }

        return answer;
}
