#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2005;

int N, M;
vector<int> G[MAXN];
bool vis[MAXN];

bool dfs(int v, int depth) 
{
        if (depth == 4) 
        {
                return true;
        }

        vis[v] = true;
        bool found = false;
        for (int u : G[v]) 
        {
                if (!vis[u]) 
                {
                        found = dfs(u, depth + 1);
                        if (found) 
                                break;

                }
        }
        vis[v] = false;
        return found;
}

int main() 
{
        cin >> N >> M;
        for (int i = 0; i < M; i++) 
        {
                int a, b;
                cin >> a >> b;
                G[a].push_back(b);
                G[b].push_back(a);
        }

        bool path_exists = false;

        for (int i = 0; i < N; i++) 
        {
                fill(vis, vis + N, false);

                if (dfs(i, 0))
                {
                        path_exists = true;
                        break;
                }
        }

        std::cout << path_exists ? 1 : 0;
        

        return 0;
}