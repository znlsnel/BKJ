#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<string> answers;
vector<bool> visited_u;
vector<bool> visited_b;

bool CHECK(string& user, string& banned)
{
        if (user.size() != banned.size())
                return false;

        for (int i = 0; i < user.size(); i++)
        {
                if (user[i] != banned[i] && banned[i] != '*')
                        return false;
        }
        return true;
}

void DFS(vector<string>& user, vector<string>& banned, int bidx, vector<string> found)
{
        if (found.size() == banned.size())
        {
                sort(found.begin(), found.end());
                string ret = "";
                for (string& s : found)
                        ret += s;
                answers.insert(ret);
                return;
        }

        for (int i = bidx; i < banned.size(); i++)
        {
                if (visited_b[i]) continue;

                for (int j = 0; j < user.size(); j++)
                {
                        if (visited_u[j]) continue;

                        if (CHECK(user[j], banned[i]))
                        {
                                visited_b[i] = true; visited_u[j] = true;
                                found.push_back(user[j]);
                                DFS(user, banned, i + 1, found);
                                found.pop_back();

                        }
                        visited_b[i] = false; visited_u[j] = false;
                }
        }
}

int solution(vector<string> user_id, vector<string> banned_id) {
        visited_u.resize(user_id.size());
        visited_b.resize(banned_id.size());

        DFS(user_id, banned_id, 0, vector<string>());
        return answers.size();
}