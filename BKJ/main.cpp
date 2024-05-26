#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> _diceSet;
vector<vector<int>> _diceCombi;
vector<vector<int>> diceCombis;

void GenerateDiceSets(vector<int>v, vector<bool> visited, int size)
{
        if (v.size() == size / 2)
        {
                _diceSet.push_back(v);
                return;
        }

        for (int i = 0; i < size; i++)
        {
                if (visited[i])
                        continue;

                visited[i] = true;

                vector<bool> newB = visited;
                vector<int> newV = v;
                newV.push_back(i);

                GenerateDiceSets(newV, newB, size);
        }
}

void GenerateDiceCombis(vector<int>v, int size, int start = 0)
{
        if (v.size() == size / 2)
        {
                _diceCombi.push_back(v);
                return;
        }

        for (int i = start; i < 6; i++)
        {
                vector<int> newV = v;
                newV.push_back(i);

                GenerateDiceCombis(newV, size, start);
        }
}

int compare(int a, int b)
{
        int result = 0;

        for (int cur : diceCombis[a])
        {
                int start = 0;
                int end = diceCombis[b].size() - 1;
                while (start <= end)
                {
                        int mid = (start + end) / 2;

                        if (diceCombis[b][mid] >= cur) {
                                end = mid - 1;
                        }

                        else {
                                start = mid + 1;
                        }
                }
                result += start;
        }

        return result;
}

vector<int> solution(vector<vector<int>> dice) {

        GenerateDiceSets(vector<int>(), vector<bool>(dice.size()), dice.size());
        GenerateDiceCombis(vector<int>(), dice.size());

        for (auto diceSet : _diceSet)
        {
                vector<int> numbers;
                for (auto c : _diceCombi)
                {
                        int temp = 0;
                        for (int i = 0; i < c.size(); i++)
                        {
                                int a = diceSet[i];
                                temp += dice[a][c[i]];
                        }
                        numbers.push_back(temp);
                }
                sort(numbers.begin(), numbers.end());
                diceCombis.push_back(numbers);
        }


        int maxId = 0;
        vector<int> v(_diceSet.size());
        for (int i = 0; i < _diceSet.size(); i++)
        {
                int target = _diceSet.size() - i - 1;
                v[i] = compare(i, target);

                if (v[maxId] < v[i])
                        maxId = i;
        }

        for (int& i : _diceSet[maxId])
                ++i;

        return _diceSet[maxId];
}