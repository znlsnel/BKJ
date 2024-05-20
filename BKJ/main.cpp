#include <iostream>
#include <vector>
#include <random>
#include <algorithm> 

using namespace std;


static int N, M, Count = 1000000000;
static vector<string> v;
void answer(int x, int y)
{
        int count = 0;
        int count1 = 0;

        char startColor = v[y][x];
        char otherColor = startColor == 'W' ? 'B' : 'W';

        for (int i = y; i < y + 8; i++)
        {
                char curColor = (i - y)% 2 == 0 ? startColor : otherColor;
                for (int j = x; j < x + 8; j++)
                {
                        if (v[i][j] != curColor)
                                count++;
                        else
                                count1++;

                        curColor = curColor == 'W' ? 'B' : 'W'; 
                }
        }
        Count = min(Count, min(count, count1)); 
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);
         
        cin >> N >> M;
        v.resize(N);
        for (int i = 0; i < N; i++)
                cin >> v[i];

        // 10 * 20 
        for (int i = 0; i <= N - 8; i++)
        { 
                for (int j = 0; j <= M - 8; j++)
                {
                        answer(j, i);
                } 
        } 
        cout << Count << "\n";

} 

