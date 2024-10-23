#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

void GenerateDiceSets(vector<vector<int>>& combis, int size,
        vector<int> combi = vector<int>(), int idx = 0)
{
        if (combi.size() == size)
        {
                combis.push_back(combi);
                return;
        }

        for (int i = idx; i < size * 2; i++)
        {
                vector<int> v = combi;
                v.push_back(i);
                GenerateDiceSets(combis, size, v, i + 1);
        }
}

void GenerateNumCombis(vector<vector<int>>& diceNumCombi, int size, vector<int> v = vector<int>(), int idx = 0)
{
        if (v.size() == size)
        {
                diceNumCombi.push_back(v);
                return;
        }

        for (int i = 0; i < 6; i++)
        {
                v.push_back(i);
                GenerateNumCombis(diceNumCombi, size, v, i);
                v.pop_back();
        }
}

vector<int> GetDiceCombi(vector<vector<int>>& dice, vector<vector<int>>& diceNumCombi, vector<int>& diceSet)
{
        vector<int> ret;

        for (int i = 0; i < diceNumCombi.size(); i++)
        {
                int num = 0;
                for (int j = 0; j < diceNumCombi[i].size(); j++)
                        num += dice[diceSet[j]][diceNumCombi[i][j]];
                ret.push_back(num);
        }
        sort(ret.begin(), ret.end());

        return ret;
}

bool CHECK(vector<int>& set_A, vector<int>& set_B)
{
        for (int a : set_A)
                for (int b : set_B)
                        if (a == b)
                                return false;

        return true;
}

int Fight(vector<int>& A, vector<int>& B)
{
        int ret = 0;
        for (int num : A)
        {
                int start = 0;
                int end = B.size() - 1;

                while (start <= end)
                {
                        int mid = (start + end) / 2;
                        if (B[mid] >= num)
                                end = mid - 1;
                        else
                                start = mid + 1;
                }
                ret += start;
        }

        return ret;
}

vector<int> solution(vector<vector<int>> dice) {
        int n = dice.size();

        // 다이스 조합 (1번, 2번 -- -- - -)
        vector<vector<int>> diceSets;
        GenerateDiceSets(diceSets, n / 2);

        // 주사위를 던졌을 때 나오는 숫자의 조합 ( 1 ~ 6 )
        vector<vector<int>> diceNumCombis;
        GenerateNumCombis(diceNumCombis, n / 2);

        // 나올 수 있는 모든 숫자 조합
        vector<vector<int>> diceCombis;
        for (int i = 0; i < diceSets.size(); i++)
                diceCombis.push_back(GetDiceCombi(dice, diceNumCombis, diceSets[i]));

        vector<int> scores(diceSets.size());
        // 승 무 패 기록하기
        for (int i = 0; i < diceSets.size() - 1; i++)
        {
                for (int j = i + 1; j < diceSets.size(); j++)
                {
                        // 겹치는 번호가 있는지 체크 
                        if (!CHECK(diceSets[i], diceSets[j]))
                                continue;

                        vector<int>& myCombi = diceCombis[i];
                        vector<int>& target = diceCombis[j];

                        scores[i] += Fight(myCombi, target);
                        scores[j] += Fight(target, myCombi);
                }
        }

        int topIdx = 0;
        int topScore = 0;
        for (int i = 0; i < scores.size(); i++)
        {
                if (scores[i] > topScore)
                {
                        topScore = scores[i];
                        topIdx = i;
                }
        }

        for (int& n : diceSets[topIdx])
                n += 1;
        return diceSets[topIdx];
}

// A와 B가 N개의 주사위를 가지고 승부를 시작!
// 각 주사위는 면에 적힌 수가 다름
// A가 먼저 절반의 주사위를 가져감
// 어떤 주사위를 가져가야 승률이 가장 높을까?

// 조합별 승, 무, 패를 기록하는 방식으로 승이 가장 많은 애를 가져가면 될듯
// [1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]
//
// 주사위의 경우의 수
// for (int i = 1; i < 4; i++)
//     for (int j = i + 1; j < 4; j++)

// i 주사위와 j 주사위를 가지고 있을 때 다른 주사위들과 승부 시작

// 다른 주사위의 경우의 수
// for (int k = 1; k < 4; k++)
//     for (int l = k + 1; l < 4; l++)
//          if (k == i || k == j || l == i || l == j)
//              continue;

// n의 길이는 최대 10, 즉 10 * 10 * 10 * 10 => 10000

// [i,j] 주사위 조합 vs [k, l] 주사위 조합 (면의 개수 = 6)
// for (int i = 0; i < 6; i++) 
//      for (int j = i + 1; j < 6; j++)
// 총 6 * 6 번의 경우의 수 등장 (36개)
// 상대 조합도 36개
// 주사위 조합별로 저장하면 될듯 (map<pair<int, int>>, vector<int>> combis)

// 36개 vs 36개 조합이니 36 * 36 = 1296번의 승부가 발생됨
// 1296번의 승부를 통해 승, 무, 패 기록


