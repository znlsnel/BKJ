#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;

long v[4][2];

bool isCross(); 
int CCW(long v1[2], long v2[2], long v3[2]);
bool isOverlab();

// CCW  = A(x, y), B(x, y), C(x, y) -> 
// (A.x*B.y + B.x*C.y + C.x*A.y) - (A.x*C.y + B.x*A.y + C.x*B.y)  
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        for (int i = 0; i < 4; i++)
        { 
                int a, b;
                cin >> a >> b;
                v[i][0] = a;
                v[i][1] = b;
        }

        int result = isCross() ? 1 : 0;
        cout << result << "\n"; 
} 

int CCW(long v1[2], long v2[2], long v3[2])
{ 
        long result = (v1[0] * v2[1] + v2[0] * v3[1] + v3[0] * v1[1]) - (v1[0] * v3[1] + v2[0] * v1[1] + v3[0] * v2[1]);
        return result > 0 ? 1 : result < 0 ? -1 : 0;
}
 
bool isOverlab()
{
        if (min(v[0][0], v[1][0]) <= max(v[2][0], v[3][0]) && min(v[2][0], v[3][0]) <= max(v[0][0], v[1][0]))
        {
                if (min(v[0][1], v[1][1]) <= max(v[2][1], v[3][1]) && min(v[2][1], v[3][1]) <= max(v[0][1], v[1][1]))
                        return true; 
        }
        return false;
} 
 
bool isCross()
{ 
        int abc = CCW(v[0], v[1], v[2]);
        int abd = CCW(v[0], v[1], v[3]);
        int cda = CCW(v[2], v[3], v[0]);
        int cdb = CCW(v[2], v[3], v[1]); 

        if (abc * abd == 0 && cda * cdb == 0) { 
                return isOverlab();
        }
        else if (abc * abd <= 0 && cda * cdb <= 0)
                return true;
        else
                return false;
}
