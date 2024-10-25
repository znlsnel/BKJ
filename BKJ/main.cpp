#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {

        int hp = health;
        int healCnt = 0;

        int time = 0;
        int idx = 0;
        while (idx < attacks.size())
        {
                // 공격 받을 시간이 됐다면 ?
                if (attacks[idx][0] == time)
                {
                        hp -= attacks[idx++][1];
                        healCnt = 0;
                        if (hp <= 0)
                                return -1;
                }
                else
                {
                        hp += bandage[1];
                        if (++healCnt == bandage[0])
                        {
                                healCnt = 0;
                                hp += bandage[2];
                        }
                        hp = min(hp, health);
                }

                //  cout << "TIME : " << time << " IDX : " << idx << " HP : " << hp <<"\n";
                time++;
        }

        return hp;
}

// bandage = [시전 시간, 초당 회복량, 추가 회복량(시전 시간 채웠을 경우))]
// health = 최대 체력
// attacks = [[공격 받는 시간, 피해량], ... ... ... ]