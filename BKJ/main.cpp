#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int find(vector<int>& parents, int a)
{
        if (a == parents[a])
                return a;

        return parents[a] = find(parents, parents[a]);
}

void Union(vector<int>& parents, int a, int b)
{
        a = find(parents, a);
        b = find(parents, b);

        if (a <= b)
                parents[b] = a;
        else
                parents[a] = b;
}



int solution(int n, vector<vector<int>> wires)
{
        int answer = 100000000;

        for (int i = 0; i < wires.size(); i++)
        {
                vector<int> parents(n);
                for (int j = 0; j < parents.size(); j++)
                        parents[j] = j;

                map<int, int> m;
                for (int j = 0; j < wires.size(); j++)
                {
                        if (j == i)
                                continue;

                        int a = wires[j][0] - 1;
                        int b = wires[j][1] - 1;

                        Union(parents, a, b);
                }
                for (int n : parents)
                        m[find(parents, n)]++;

                vector<int> idxs;
                for (auto a : m)
                        idxs.push_back(a.first);

                answer = min(answer, abs(m[idxs[0]] - m[idxs[1]]));
        }


        return answer;
}