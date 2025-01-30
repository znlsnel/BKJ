#include <string>
#include <set>
#include <iostream>

using namespace std;

int clamp(int t, int a, int b)
{
        if (t < a)
                t = a;
        else if (t > b)
                t = b;

        return t;
}
int solution(string dirs) {
        int answer = 0;

        set<pair<int, int>> roads;
        int cy = 0, cx = 0;

        for (char dir : dirs)
        {
                auto [ny, nx] = make_pair(cy, cx);

                if (dir == 'U')
                        ny += 1;
                else if (dir == 'D')
                        ny -= 1;
                else if (dir == 'R')
                        nx += 1;
                else if (dir == 'L')
                        nx -= 1;

                ny = clamp(ny, -5, 5);
                nx = clamp(nx, -5, 5);

                int idxC = cy * 11 + cx;
                int idxN = ny * 11 + nx;

                if (idxC != idxN)
                        roads.insert({ min(idxC, idxN), max(idxC, idxN) });

                cy = ny;
                cx = nx;
        }



        return roads.size();
}
