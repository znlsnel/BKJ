#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int N;
static vector<pair<int, int>> M;
static long D[502][502];
int execute(int s, int e);

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        cin >> N;
        M.resize(N + 1);
        
        for (int i = 0; i < N + 1; i++)
        {
                for (int j = 0; j < N + 1; j++)
                        D[i][j] = -1;
        }

        for (int i = 1; i <= N; i++)
        {
                int y, x;
                cin >> y >> x;
                M[i] = make_pair(y, x);
        }
        cout << execute(1, N) << "\n"; 
}

int execute(int s, int e)
{
        int result = 1000000000;

        if (D[s][e] != -1)
                return D[s][e]; 

        if (s == e)
                return 0;

        if (s + 1 == e)
        {
                return M[s].first * M[s].second * M[e].second;  
        }
        
        for (int i = s; i < e; i++)
        {
                result = min(
                        result, 
                        M[s].first * M[i].second * M[e].second + execute(s, i) + execute(i + 1, e));  
        }
        
        return D[s][e] = result;
}
 