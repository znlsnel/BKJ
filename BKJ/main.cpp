#include <iostream>
#include <vector>
#include <random>
#include <algorithm> 

using namespace std;


static int N, Count;
 
struct Pos
{
        int x;
        int y;

        void operator+=(Pos other) {
                x += other.x;
                y += other.y; 
        }

        Pos operator -(Pos other) {
                Pos result;
                result.x = x - other.x;
                result.y = y - other.y;

                return result;
        }
};

bool Check(vector<int>& v, Pos pos)
{  
        for (int i = 0; i < v.size(); i++)
        {
                Pos prev = Pos{ i, v[i] };
                Pos cur = pos;
                
                Pos dir = prev - cur;

                // (상 하 좌 우) 방향
                if (dir.x * dir.y == 0)
                        return false;

                // 대각 방향
                if (abs(dir.x) - abs(dir.y) == 0)
                        return false;
                
        }
        return true;
}

void result(vector<int> v)
{
        //cout << v.size() << "\n";
        if (v.size() == N) {
                Count++; 
                return;
        }
          
        for (int j = 0; j < N; j++)
        {
                if (Check(v, Pos{ int(v.size()), j})) 
                {
                        vector<int> nextV = v;
                        nextV.push_back(j); 

                        result(nextV);  
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);
         
        cin >> N;
        for (int i = 0; i < N; i++)
        { 
                vector<int> v;
                v.push_back(i);
                result(v);  
        } 
       
        cout << Count;
} 

