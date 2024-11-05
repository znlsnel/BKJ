#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
        long long count = 0;

        for (int x = 1; x <= r2; ++x)
        {
                int max_y = int(floor(sqrt((long long)(r2)*r2 - (long long)(x)*x)));

                int min_y = (x >= r1) ? 0 : int(ceil(sqrt((long long)(r1)*r1 - (long long)(x)*x)));

                count += (max_y - min_y + 1);
        }
        return count * 4;
}
