#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
        // 초기 시작 지점과 끝 지점을 설정 (0-based index로 변경)
        long long startX = x, endX = x, startY = y, endY = y;

        // 명령어를 역순으로 처리
        for (int i = queries.size() - 1; i >= 0; --i) {
                int direction = queries[i][0];
                int distance = queries[i][1];

                if (direction == 0)
                { // Left
                        if (startY != 0)
                        {
                                startY += distance;
                        }

                        endY = min((long long)m - 1, endY + distance);
                }

                else if (direction == 1)
                { // Right
                        if (endY != m - 1)
                        {
                                endY -= distance;
                        }

                        startY = max(0LL, startY - distance);
                }

                else if (direction == 2)
                { // Up
                        if (startX != 0)
                        {
                                startX += distance;
                        }

                        endX = min((long long)n - 1, endX + distance);
                }

                else if (direction == 3)
                { // Down
                        if (endX != n - 1)
                        {
                                endX -= distance;
                        }
                        startX = max(0LL, startX - distance);
                }

                // 격자 범위를 벗어난 경우
                if (startX >= n || startY >= m || endX < 0 || endY < 0) {
                        return 0;
                }

                // 시작점이 끝점을 넘어서면 안됨
                startX = max(0LL, startX);
                startY = max(0LL, startY);
                endX = min((long long)n - 1, endX);
                endY = min((long long)m - 1, endY);
        }

        // 가능한 영역의 크기를 반환
        return (endX - startX + 1) * (endY - startY + 1);
}