#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int drop(vector<vector<int>>& tree, vector<int>& road) {
        //x번 노드가 현재 road[x]번째 자식노드를 가리키고 있다. 

        int node = 1;// [게임의 규칙] 1.
        while (!tree[node].empty()) {// [게임의 규칙] 2.
                int nx = tree[node][road[node]];
                road[node] = (road[node] + 1) % tree[node].size();// [게임의 규칙] 3.
                node = nx;
        }
        return node;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {

        vector<vector<int>> tree(edges.size() + 2);

        for (auto e : edges)
                tree[e[0]].push_back(e[1]);

        //[게임의 규칙] 3. 과, 
        //가장 번호가 작은 노드를 가리키는 간선을 초기 길로 설정한다는 조건을 위해 정렬한다.

        for (int i = 0; i < tree.size(); i++)
                sort(tree[i].begin(), tree[i].end());

        vector<int> road(tree.size(), 0);
        vector<int> stacked(tree.size(), 0);
        vector<int> simulation;

        vector<bool> enough(tree.size(), 0);

        // 원래 0인거 찾기
        int cnt = 0;
        for (int i = 0; i < target.size(); i++)
        {
                if (target[i] == 0)
                {
                        enough[i] = 1;
                        cnt++;
                }
        }

        cout << cnt << "\n";

        // 리프노드 갯수 만큼
        while (cnt < target.size())
        {
                //x번 노드의 정보가 target[x-1]에 있으므로, -1해줘야함.
                int x = drop(tree, road) - 1;
                simulation.push_back(x);
                stacked[x]++;

                if (target[x] < stacked[x])
                        return { -1 };//과하게 쌓인 경우.

                if (target[x] <= stacked[x] * 3)
                {
                        if (!enough[x])
                        {
                                cnt++;
                                enough[x] = 1;    //충분히 쌓인 경우.
                        }
                }
        }

        vector<int> result;
        for (auto i : simulation) {
                int x = max(1, target[i] - (stacked[i] - 1) * 3);
                target[i] -= x;
                stacked[i]--;
                result.push_back(x);
        }
        return result;
}