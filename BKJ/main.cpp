#include <vector>
#include <algorithm>

using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {

        vector<int> cnt(1321);
        for (auto& time : timetable)
                for (int i = time[0]; i <= time[1]; i++)
                        cnt[i]++;

        int people = *max_element(cnt.begin(), cnt.end());
        if (people <= 1)
                return 0;


        for (int d = 2 * n - 2; d > 0; d--)
        {
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < n; j++)
                        {
                                vector<pair<int, int>> use({ {i, j} });

                                for (int y = 0; y < n; y++)
                                {
                                        for (int x = 0; x < n; x++)
                                        {

                                                bool flag = true;
                                                for (auto& p : use)
                                                {
                                                        int dist = abs(p.first - y) + abs(p.second - x);
                                                        if (dist < d)
                                                        {
                                                                flag = false;
                                                                break;
                                                        }
                                                }

                                                if (flag)
                                                {
                                                        use.push_back({ y, x });
                                                        if (people == use.size())
                                                                return d;
                                                }

                                        }

                                }
                        }
                }
        }




        return 0;


}