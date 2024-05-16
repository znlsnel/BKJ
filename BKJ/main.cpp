#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


static int D[30];

// CCW  = A(x, y), B(x, y), C(x, y) -> 
// (A.x*B.y + B.x*C.y + C.x*A.y) - (A.x*C.y + B.x*A.y + C.x*B.y)  
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        int v[3][2];
        int n = 3;
        for (int i = 0; i < 3; i++)
        {
                int a, b;
                cin >> a >> b;
                v[i][0] = a;
                v[i][1] = b;
        }
         
         
        int result = (v[0][0]*v[1][1] + v[1][0]*v[2][1] + v[2][0]*v[0][1])
                -  (v[0][0]*v[2][1] + v[1][0] * v[0][1] + v[2][0] * v[1][1]); 
        
        result = result > 0 ? 1 : result < 0 ? -1 : 0;
        cout << result << "\n";
}
