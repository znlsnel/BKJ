#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
        int answer = 0;

        for (int i = 0; i < cookie.size() - 1; i++)
        {
                int l = i;
                int r = l + 1;
                int lsum = cookie[l];
                int rsum = cookie[r];

                while (true)
                {
                        if (lsum == rsum)
                                answer = max(lsum, answer);

                        if (0 < l && lsum <= rsum)
                                lsum += cookie[--l];

                        else if (r < cookie.size() - 1 && lsum >= rsum)
                                rsum += cookie[++r];

                        else
                                break;

                }
        }

        return answer;
}