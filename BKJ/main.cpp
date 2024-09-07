#include <iostream>
#include <vector>
using namespace std;

int GetCost(int length, int w)
{
        int ret = length / (w * 2 + 1);
        ret += length % (w * 2 + 1) > 0 ? 1 : 0;
        return ret;
}
int solution(int n, vector<int> stations, int w)
{
        int answer  = GetCost((stations[0] - w) - 1, w);

        for (int i  = 1; i  < stations.size(); i++)
        {
                int left = stations[i - 1] + w + 1;
                int right = stations[i] - w - 1;

                // left -> 6, right -> 9일 때 길이는 4
                int length = right - left + 1;
                answer += GetCost(length, w);
        }
        answer += GetCost(n - (stations[stations.size() - 1] + w), w);

        return answer;
}