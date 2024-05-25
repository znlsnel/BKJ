#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> _diceSet;
vector<vector<int>> _diceCombi;
vector<vector<int>> diceCombis;


struct Node
{
        vector<vector<int>>* _diceCombis = nullptr;

        int index = 0;

        Node* _left = nullptr;
        Node* _right = nullptr;

        Node(vector<vector<int>>* diceCombis, int id)
        {
                _diceCombis = diceCombis;
                index = id;
        }

        void Insert(int id)
        {
                int a = 0, b = 0;
                int winner = compare(index, id, a, b);

                if (winner == index)
                {
                        if (_right == nullptr)
                                _right = new Node(_diceCombis, id);

                        else
                                _right->Insert(id);
                }
                else
                {
                        if (_left == nullptr)
                                _left = new Node(_diceCombis, id);

                        else
                                _left->Insert(id);
                }

        }

        int compare(int a, int b, int& score_A, int& score_B)
        {

                vector<vector<int>>& diceCombis = *_diceCombis;

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
                        score_A += diceCombis[b][start] < cur ? start + 1 : start;
                }

                for (int cur : diceCombis[b])
                {
                        int start = 0;
                        int end = diceCombis[a].size() - 1;
                        while (start <= end)
                        {
                                int mid = (start + end) / 2;

                                if (diceCombis[a][mid] >= cur) {
                                        end = mid - 1;
                                }

                                else {
                                        start = mid + 1;
                                }
                        }
                        score_B += diceCombis[a][start] < cur ? start + 1 : start;
                }

                /*cout << "======= FIGHT ! ! ========\n";
                cout << a << ": \n";
                for (int i : diceCombis[a])
                    cout << i << ", ";
                cout << "\n";
                cout << "score : " << score_A << "\n";

                cout << b << ": \n";
                for (int i : diceCombis[b])
                    cout << i << ", ";
                cout << "\n";
                cout <<"score : " << score_B << "\n";

                cout <<"\n\n";*/

                //score = max(score_A, score_B);

                return score_A >= score_B ? a : b;
        }

        void Inorder(vector<int>* v)
        {
                if (_left != nullptr)
                        _left->Inorder(v);

                if (v->size() == 0)
                {
                        v->push_back(index);
                }
        }
};


void MakeSet(vector<int>v, vector<bool> visited, int size)
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

                MakeSet(newV, newB, size);
        }
}

void MakeSet2(vector<int>v, int size, int start = 0)
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

                MakeSet2(newV, size, start);
        }
}


vector<int> solution(vector<vector<int>> dice) {
        vector<int> answer;

        MakeSet(vector<int>(), vector<bool>(dice.size()), dice.size());
        MakeSet2(vector<int>(), dice.size());

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


        Node* node = new Node(&diceCombis, 0);
        for (int i = 1; i < _diceSet.size(); i++)
                node->Insert(i);

        /* vector<int> v(_diceSet.size());
         for (int i = 0; i < _diceSet.size(); i++){
             for (int j = i + 1; j < _diceSet.size(); j++)
             {
                 int a = 0;
                 int b = 0;
                 node->compare(i, j, a, b);
                 v[i] += a;
                 v[j] += b;
             }
         }
         int maxId = 0;
         for (int i = 1; i < v.size(); i++)
         {
             if (v[maxId] < v[i])
                 maxId = i;
         }*/


        node->Inorder(&answer);
        answer = _diceSet[answer[0]];
        for (int& i : answer)
                ++i;

        return answer;
}