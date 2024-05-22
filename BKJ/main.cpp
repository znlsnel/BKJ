#include <vector>
#include <iostream>
#include <queue>
using namespace std;

static int _newNode, _donutCount, _barCount, _eightCount;
static vector<vector<int>> v;
static vector<pair<int, int>> degree; // in, out
static vector<bool> visited;

void BFS(int start)
{
        int edgeCount = 0;
        int nodeCount = 1;

        queue<int> q;
        q.push(start);

        while (q.size())
        {
                int cur = q.front();
                q.pop();

                visited[cur] = true;

                for (int next : v[cur])
                {
                        edgeCount++;

                        if (visited[next] == false) {
                                nodeCount++;
                                q.push(next);
                        }
                }
        }

        if (edgeCount == nodeCount - 1) {
                //  cout << "########## BAR COUNT UP ! ! ! ##########" << "\n"  ;
                _barCount++;
        }

        else if (edgeCount == nodeCount + 1) {

                //cout << "########## EIGHT COUNT UP ! ! ! ##########" << "\n"  ;
                _eightCount++;

        }
        else if (edgeCount == nodeCount)
        {
                //cout << "########## DONUT COUNT UP ! ! ! ##########" << "\n"  ;
                _donutCount++;
        }
        cout << "\n";


}

// 도넛 - 자기 자신을 순회
// 바 - 엣지 수 == 노드 수 - 1
// 8 - 엣지수 == 노드 수 + 1 && 도넛이 아닐때
// 1. 새롭게 추가된 노드를 찾기
// 2. New Node 를 제외한 모든 노드 DFS (방문 했으면 안하기)
// 3. 마지막 New Node DFS

vector<int> solution(vector<vector<int>> edges)
{
        int size = 0;
        for (auto edge : edges)
                for (auto i : edge)
                        size = max(size, i);

        v.resize(size + 1);
        degree.resize(size + 1);
        visited.resize(size + 1);

        for (auto edge : edges)
        {
                v[edge[0]].push_back(edge[1]);
                degree[edge[0]].second++;
                degree[edge[1]].first++;
        }

        for (int i = 0; i < degree.size(); i++)
        {
                if (degree[i].first == 0 && degree[i].second >= 2)
                        _newNode = i;
        }

        for (int i : v[_newNode])
                BFS(i);


        return { _newNode, _donutCount, _barCount, _eightCount };
}
int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);


} 

