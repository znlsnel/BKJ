#include<bits/stdc++.h>
using namespace std;

int solution(string name) {
        int alphaMove[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
        int ans = 0, n = name.size();
        int minMove = n - 1;
        for (int x = 0; x < n; x++) {
                ans += alphaMove[name[x] - 'A'];
                int y = x + 1; // x 오른쪽에 있으면서 A가 아닌 문자가 있는 위치를 y라하자

                while (y < n && name[y] == 'A')
                        y++;

                minMove = min(minMove, min(x + x + (n - y), x + (n - y) + (n - y)));
        }
        ans += minMove;
        return ans;
}