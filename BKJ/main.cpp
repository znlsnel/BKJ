#include <iostream>
#include <vector>
#include <random>
#include <algorithm> 

using namespace std;
static int N, M, K, Count;
static int v[51][51];
static bool visited[51][51];

struct Pos
{
        int i;
        int j;

        void operator+=(Pos other)
        {
                this->i += other.i;
                this->j += other.j;
        }

        void operator-=(Pos other)
        {
                this->i -= other.i;
                this->j -= other.j;
        } 

        Pos operator+(Pos other)
        {
                Pos result;
                result.i = this->i + other.i;
                result.j = this->j + other.j;
                return result;
        }

        Pos operator-(Pos other)
        {
                Pos result;
                result.i = this->i - other.i;
                result.j = this->j - other.j;
                return result;
        }
};

Pos dir[4] = {
        {0, -1},
        {0, 1},
        {1, 0},
        {-1, 0}
};

bool DFS(Pos pos)
{
        if (visited[pos.i][pos.j] || v[pos.i][pos.j] == 0)
                return false;

        visited[pos.i][pos.j] = true;

        for (int i = 0; i < 4; i++)
        {
                Pos next = pos + dir[i];
                if (next.i < 0 || next.i > N || next.j < 0 || next.j > M)
                        continue;

                if (v[next.i][next.j] == 0 || visited[next.i][next.j])
                        continue;
                 
                DFS(next); 
        }
        return true;
}


void answer()
{
        cin >> N >> M >> K;
        
        Count = 0;
        for (int i = 0; i < N; i++)
        { 
                std::fill(&v[i][0], &v[i][M], 0);
                std::fill(&visited[i][0], &visited[i][M], false);
        }  

        for (int i = 0; i < K; i++)
        {
                int a, b;
                cin >> a >> b;

                v[a][b] = 1; 
        }
         

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        if (DFS(Pos{i, j})) 
                                Count++; 
                }
        }
        cout << Count << "\n";
} 
 
int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        int T;
        cin >> T;

        while (T--)
                answer();
        

} 

