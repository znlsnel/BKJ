#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <queue>
#include <algorithm> 

using namespace std;

struct vertex {
        int x;
        int y;
};

struct edge {
        vertex v1;
        vertex v2;
};

vector<edge> v;
vector<int> parent;
// CCW  = A(x, y), B(x, y), C(x, y) -> 
// (A.x*B.y + B.x*C.y + C.x*A.y) - (A.x*C.y + B.x*A.y + C.x*B.y)   

bool isOverlap();
int CCW(vertex v1, vertex v2, vertex v3);
bool isCross(int id1, int id2);
void Union(int a, int b);
int find(int a); 

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                vertex v1 = vertex{ a, b };
                vertex v2 = vertex{ c, d };
                 
                v.push_back({v1, v2});
        }
        parent.resize(N + 1, -1);

        for (int i = 1; i < N; i++) 
        { 
                for (int j = 0; j < i; j++) {
                        bool result = isCross(i, j);
                        if (result) 
                        {
                                Union(i, j);
                        }
                }
        }
         
        int groupCount = 0;
        int edgeCount = 0;
        for (int i = 0; i < N; i++)
        {
                if (parent[i] < 0)
                {
                        groupCount++;
                        edgeCount = min(edgeCount, parent[i]);
                }
        } 

        cout << groupCount << "\n" << -edgeCount << "\n"; 
} 


void Union(int a, int b)
{
        a = find(a);
        b = find(b);
        
        if (a == b)
                return;

        parent[a] += parent[b];
        parent[b] = a; 
}
 
int find(int a)
{
        if (parent[a] < 0)
                return a;

        return parent[a] = find(parent[a]);

}

bool isOverlap(edge e1, edge e2) 
{
        bool isOverlapX = min(e1.v1.x, e1.v2.x) <= max(e2.v1.x, e2.v2.x) && min(e2.v1.x, e2.v2.x) <= max(e1.v1.x, e1.v2.x);
        bool isOverlapY = min(e1.v1.y, e1.v2.y) <= max(e2.v1.y, e2.v2.y) && min(e2.v1.y, e2.v2.y) <= max(e1.v1.y, e1.v2.y);

        return isOverlapX && isOverlapY; 
} 

// (A.x*B.y + B.x*C.y + C.x*A.y) - (A.x*C.y + B.x*A.y + C.x*B.y)   
int CCW(vertex v1, vertex v2, vertex v3)
{
        int result = (v1.x*v2.y + v2.x*v3.y + v3.x*v1.y) - (v1.x*v3.y + v2.x*v1.y + v3.x*v2.y);
        result = std::clamp(result, -1, 1);  
        return result;
} 
 
bool isCross(int id1, int id2)
{
        edge e1 = v[id1];
        edge e2 = v[id2];

        int abc = CCW(e1.v1, e1.v2, e2.v1);
        int abd = CCW(e1.v1, e1.v2, e2.v2);
        int cda = CCW(e2.v1, e2.v2, e1.v1);
        int cdb = CCW(e2.v1, e2.v2, e1.v2); 
         
        if (abc * abd == 0 && cda * cdb == 0) {
                return isOverlap(e1, e2);
        }
        else if (abc * abd <= 0 && cda * cdb <= 0)
        {
                return true;
        }
        return false;
}