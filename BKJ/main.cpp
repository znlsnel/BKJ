#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int stoh(string str)
{
        int ret = 0;
        for (char c : str)
        {
                ret += c - 'a';
        }
        return ret;
}

struct Genre
{
        string name;

        int total;

        int first;
        int second;

        int first_id;
        int second_id;

        void AddPlayTime(int t, int idx)
        {
                total += t;
                if (first < t)
                {
                        second = first;
                        second_id = first_id;

                        first = t;
                        first_id = idx;

                }
                else if (second < t)
                {
                        second = t;
                        second_id = idx;
                }

        }
};

struct Node
{
        Node* left = nullptr;
        Node* right = nullptr;

        int strId = -1;
        vector<Genre> genres;

        void Add(string str, int strId, int value, int id)
        {
                if (this->strId == strId)
                {
                        int genreID = -1;
                        for (int i = 0; i < genres.size(); i++)
                        {
                                if (genres[i].name == str)
                                {
                                        genreID = i;
                                        break;
                                }
                        }
                        if (genreID == -1)
                        {
                                Genre g{ str, 0, 0, -1, -1 };
                                g.AddPlayTime(value, id);

                                genres.push_back(g);
                        }
                        else
                        {
                                genres[genreID].AddPlayTime(value, id);
                        }
                }
                else if (this->strId > strId)
                {
                        // 왼쪽
                        if (left == nullptr)
                        {
                                left = new Node();
                                left->strId = strId;
                        }
                        left->Add(str, strId, value, id);

                }
                else if (this->strId < strId)
                {
                        // 오른쪽
                        if (right == nullptr)
                        {
                                right = new Node();
                                right->strId = strId;
                        }
                        right->Add(str, strId, value, id);
                }
        }

        void GetGenres(vector<Genre>& v)
        {
                if (left != nullptr)
                        left->GetGenres(v);

                for (auto g : genres)
                        v.push_back(g);

                if (right != nullptr)
                        right->GetGenres(v);
        }
};


vector<int> solution(vector<string> genres, vector<int> plays) {
        vector<int> answer;

        Node root;
        for (int i = 0; i < genres.size(); i++)
        {
                int hash = stoh(genres[i]);
                root.Add(genres[i], hash, plays[i], i);
        }

        vector<Genre> v;
        root.GetGenres(v);

        auto compare = [](Genre a, Genre b) {
                return a.total > b.total;
                };

        sort(v.begin(), v.end(), compare);

        for (Genre& g : v)
        {
                answer.push_back(g.first_id);
                if (g.second_id != -1)
                        answer.push_back(g.second_id);
        }

        return answer;
}