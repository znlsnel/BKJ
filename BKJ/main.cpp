#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<int, vector<int>> trees;
unordered_map<int, vector<int>> tree_length;
bool visit[250002];
int max_step = -1;

void find_path(int vtx, int step)
{
        visit[vtx] = true;
        if (max_step <= step)
        {
                max_step = step;
                tree_length[max_step].push_back(vtx);
        }

        for (int idx : trees[vtx])
        {
                if (!visit[idx])
                        find_path(idx, step + 1);
        }

        visit[vtx] = false;
}

int solution(int n, vector<vector<int>> edges) {

        int answer = 0;
        for (auto& edge : edges) {
                trees[edge[0]].push_back(edge[1]);
                trees[edge[1]].push_back(edge[0]);
        }

        find_path(1, 0);
        for (int i = 0; i < 2; i++)
        {
                int nxt = tree_length[max_step][0];
                max_step = -1;
                tree_length.clear();
                find_path(nxt, 0);

                if (tree_length[max_step].size() > 1)
                        return max_step;
        }


        return max_step - 1;
}