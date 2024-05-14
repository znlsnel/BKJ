#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int INF = 1000000 * 16 + 1;
static int N;
static int W[16][16];
static int D[16][(1 << 16)];
int tsp(int c, int v); 

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        cin >> N;

        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < N; j++)
                { 
                        cin >> W[i][j];
                }
        }
        // 0번 도시에서 0001 -> 0번 도시 방문 
        cout << tsp(0, 1) << "\n"; 
}   
     
int tsp(int c, int v)
{
        if (v == (1 << N) - 1)
        {
                return W[c][0] == 0 ? INF : W[c][0];
        } 

        if (D[c][v] != 0) {
                return D[c][v];
        }

        int min_val = INF;
        for (int i = 0; i < N; i++)
        {
                // 방문한 노드x && 자기자신으로 가는게 아니어야함
                if ((v & (1 << i)) == 0 && W[c][i] != 0) {
                        min_val = min(min_val, tsp(i, (v | (1 << i))) + W[c][i]); 
                }
        } 
        D[c][v] = min_val;
        return D[c][v]; 
       
}
