#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> tops) {
        vector<int> v(n + 1);
        v[0] = 1;
        v[1] = v[0] * (3 + tops[0]);

        for (int i = 2; i <= n; i++) {
                v[i] = (v[i - 1] * (3 + tops[i - 1]) - v[i - 2]) % 10007;
                if (v[i] < 0) v[i] += 10007;  // 음수를 방지
        }

        return v[n];
}
int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);


} 

