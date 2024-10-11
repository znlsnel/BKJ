#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> cores) {
        // sort(cores.begin(), cores.end());

        int start = -1;
        int end = 1000000;

        if (n <= cores.size())
                return n;

        while (start + 1 < end)
        {
                int mid = (start + end) / 2;

                int total = cores.size();
                for (int i = 0; mid > 0 && i < cores.size(); i++)
                        total += mid / cores[i];

                if (total < n)
                        start = mid;
                else
                        end = mid;
        }

        int total = cores.size();
        for (int i = 0; i < cores.size(); i++)
                total += start / cores[i];
        for (int i = 0; i < cores.size(); i++)
        {
                if ((start + 1) % cores[i] == 0)
                        total++;
                if (total == n)
                        return i + 1;
        }



        return -1;
}

// n번째에 처리하는 cpu는 누구일까
// [1] [2] [3]
// [4] [] []
// [5] [6] []
// [7] [0] [8]
// [9] [10]


// X분에 몇개의 작업을 끝낼 수 있는지 찾기 
// X분에 N개를 처리할 수 있다면
// 마지막으로 계산한 애가 누구인지 찾기
// X분에 N-M개 처리할 수 있다면
// 마지막 + M번째에 처리하는 애 찾기