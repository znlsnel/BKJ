#include <string>
#include <vector>
#include <set>
using namespace std;

int N;
bool canGoNextRound(set<int>& hands, set<int>& machs)
{
        for (int card : hands)
        {
                int cntr = (N + 1) - card;
                for (int mach : machs)
                {
                        if (mach == cntr)
                        {
                                hands.erase(card);
                                machs.erase(mach);
                                return true;
                        }
                }
        }
        return false;
}
int solution(int coin, vector<int> cards) {
        int answer = 1;
        N = cards.size();

        set<int> hands;
        set<int> draws;

        for (int i = 0; i < cards.size() / 3; i++)
                hands.insert(cards[i]);


        for (int i = cards.size() / 3; i < cards.size(); i += 2)
        {
                draws.insert(cards[i]);
                draws.insert(cards[i + 1]);

                if (canGoNextRound(hands, hands))
                {
                        answer++;
                }
                else if (coin >= 1 && canGoNextRound(hands, draws))
                {
                        coin--;
                        answer++;
                }
                else if (coin >= 2 && canGoNextRound(draws, draws))
                {
                        coin -= 2;
                        answer++;
                }
                else
                        break;
        }


        return answer;
}