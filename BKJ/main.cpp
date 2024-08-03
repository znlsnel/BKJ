#include <string>
#include <vector>

using namespace std;


vector<int> solution(int n, int s) {
        if (s < n)
                return { -1 };

        vector<int> answer;

        int cnt = n;
        while (cnt--)
                answer.push_back(s / n);

        cnt = s % n;
        int idx = n - 1;
        while (cnt--)
                answer[idx--]++;

        return answer;
}
// 4 4 3 - 48

// 3 3 5 - 45
// 3 4 4

// 3 3 3
// 나머지 2

// 3, 9
// 3 3 3 27
// 4 3 2 24
// 5 2 2 20
// 5 3 1 15
