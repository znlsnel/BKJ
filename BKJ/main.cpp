#include <string>
#include <vector>
#include <cmath>
#include <iostream>


using namespace std;

int GetMin(int a, int b, int c, int d)
{
        return min(a, min(b, min(c, d)));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
        vector<int> answer;

        for (int i = 0; i < balls.size(); i++)
        {
                int by = balls[i][1];
                int bx = balls[i][0];
                int midY = (startY + by) / 2;
                int midX = (startX + bx) / 2;

                // 위로 날렸을 때
                pair<int, int> up = { midX, n };
                pair<int, int> down = { midX, 0 };
                pair<int, int> left = { 0, midY };
                pair<int, int> right = { m, midY };

                int upCost = pow(abs(up.first - startX) + abs(bx - up.first), 2) +
                        pow(abs(up.second - startY) + abs(by - up.second), 2);

                int downCost = pow(abs(down.first - startX) + abs(bx - down.first), 2) +
                        pow(abs(down.second - startY) + abs(by - down.second), 2);

                int leftCost = pow(abs(left.first - startX) + abs(bx - left.first), 2) +
                        pow(abs(left.second - startY) + abs(by - left.second), 2);

                int rightCost = pow(abs(right.first - startX) + abs(bx - right.first), 2) +
                        pow(abs(right.second - startY) + abs(by - right.second), 2);

                // cout << upCost << ", " << downCost << ", " << leftCost << ", " << rightCost << "\n";
                if (by == startY)
                {
                        if (bx > startX)
                                rightCost = 99999999;
                        else
                                leftCost = 99999999;
                }

                else if (bx == startX)
                {
                        if (by > startY)
                                upCost = 9999999;
                        else
                                downCost = 9999999;
                }

                answer.push_back(GetMin(upCost, downCost, leftCost, rightCost));
        }

        return answer;
}

// 왼쪽면으로 칠지, 오른쪽 면, 위, 아래 면으로 칠지 

// 3,7 -> 0, 7 -> 7,7
//     3,0     7,0
//          4, 14
//          16,14 * 14