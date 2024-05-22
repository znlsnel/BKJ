#include <string>
#include <iostream>
#include <vector>

using namespace std;


static int combine, StartNum, targetValue, specialCase;

int solution(int coin, vector<int> cards)
{
        int answer = 1;
        targetValue = cards.size() + 1;
        StartNum = cards.size() / 3;

        for (int i = 1; i < StartNum; i++)
        {
                for (int j = 0; j < i; j++)
                {
                        if (cards[i] + cards[j] == targetValue)
                                combine++;
                }
        }

        for (int i = StartNum; i < cards.size(); i += 2)
        {
                for (int j = 0; j < i; j++)
                {
                        if (j < StartNum)
                        {
                                if (coin > 0 && cards[i] + cards[j] == targetValue)
                                {
                                        combine++;
                                        coin--;
                                }

                                if (coin > 0 && cards[i + 1] + cards[j] == targetValue)
                                {
                                        combine++;
                                        coin--;
                                }
                        }
                        else
                        {
                                if (cards[i] + cards[j] == targetValue)
                                        specialCase++;

                                if (cards[i + 1] + cards[j] == targetValue)
                                        specialCase++;
                        }
                }

                if (cards[i] + cards[i + 1] == targetValue)
                {
                        specialCase++;
                }

                if (combine > 0)
                {
                        answer++;
                        combine--;
                }
                else
                {
                        if (specialCase > 0 && coin >= 2)
                        {
                                coin -= 2;
                                specialCase--;
                                answer++;
                        }
                        else
                        {
                                break;
                        }
                }

        }

        return answer;
}

int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);


} 

