#include <iostream>
#include <vector>
using namespace std;

int dp[100010];
int solution(vector<int> sticker)
{
        int answer = 0;
        int length = sticker.size();
        if (length == 1)
                return sticker[0];

        dp[0] = sticker[0];
        dp[1] = sticker[0];

        for (int i = 2; i < length - 1; i++)
                dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);

        answer = dp[length - 2];

        dp[0] = 0;
        dp[1] = sticker[1];

        for (int i = 2; i < length; i++)
                dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);

        answer = max(answer, dp[length - 1]);

        return answer;
}