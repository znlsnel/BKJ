#include <string>
#include <vector>
#include <set>

using namespace std;

pair<int, int> FindCards(set<int>& deck_A, set<int>& deck_B, int cost)
{
        for (int n : deck_A)
        {
                int target = cost - n;
                if (deck_B.find(target) != deck_B.end()) {
                        deck_A.erase(n);
                        deck_B.erase(target);
                        return { n, target };
                }
        }


        return { -1, -1 };
}


int solution(int coin, vector<int> cards) {

        set<int> myDeck;
        set<int> store;
        int n = cards.size();

        for (int i = 0; i < n / 3; i++)
                myDeck.insert(cards[i]);

        int round = 1;
        for (int i = n / 3; i < n; i += 2)
        {
                store.insert(cards[i]);
                store.insert(cards[i + 1]);

                // 내 손 안에 든 카드로 해결이 가능한지 체크
                pair<int, int> cards = FindCards(myDeck, myDeck, n + 1);
                if (cards.first == -1)
                {
                        // 돈 없으면 종료
                        if (coin < 1)
                                return round;

                        // 구매 가능한 카드 + 내 카드로 해결 가능한지 체크
                        cards = FindCards(myDeck, store, n + 1);
                        if (cards.first == -1)
                        {
                                // 구매 가능한 카드들로 해결이 가능한지 체크
                                // 돈 없거나 조합을 찾지 못했다면 종료
                                cards = FindCards(store, store, n + 1);
                                if (coin < 2 || cards.first == -1)
                                        return round;

                                coin -= 2;
                        }
                        else
                                coin--;
                }

                round++;
        }

        return round;
}
// 카드 뭉치에서 n/3 뽑음 
// 라운드별 2장 뽑음, 
// 카드 뭉치에 남은 카드 없다면 게임 종료

// 뽑은 카드는 동전 하나 소모해서 가지거나 동전 안 쓰고 버릴 수 있음
// 카드에 적힌 수의 합이 n + 1이 되도록 카드 두 장을 내고 다음 라운드로 진행 가능

// n = 12, coin = 4, cards = 3 6 7 2
// round = 1 : 3 6 7 2 1 10, coin = 2
// rount = 2 : 6 7 2 1 , coin = 2
// round = 3 : 2 1 12 , coin = 1
// round = 4 : 2 11, coin = 0
// round = 5 : x, coin = 0 -> 종료
