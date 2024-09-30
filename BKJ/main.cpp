#include <vector>
using namespace std;

int solution(int totalTasks, vector<int> cores) {
        int low = -1, high = 200000, mid = 0;

        // 이진 탐색으로 시간을 찾음
        while (low + 1 < high) {
                mid = (low + high) / 2;
                int completedTasks = cores.size(); // 코어들이 한 번씩 기본적으로 작업을 처리하는 시간 계산

                // 각 코어가 주어진 시간 내에 처리할 수 있는 작업 수 계산
                if (mid > 0) {
                        for (int i = 0; i < cores.size(); i++) {
                                completedTasks += mid / cores[i];
                        }
                }

                // 총 처리한 작업 수가 필요한 작업 수보다 적으면 더 큰 시간 범위를 탐색
                if (completedTasks < totalTasks) {
                        low = mid;
                }
                else {
                        high = mid;
                }
        }

        if (low == -1) return totalTasks; // 초기 상태에서 해결 가능한 경우

        int completedTasks = cores.size(); // 기본적으로 코어들이 처리한 작업 수
        for (int i = 0; i < cores.size(); i++) {
                completedTasks += low / cores[i]; // low 시간 동안 각 코어가 처리한 작업 수를 다시 계산
        }

        // 마지막 작업을 처리한 코어 찾기
        for (int i = 0; i < cores.size(); i++) {
                if ((low + 1) % cores[i] == 0) {
                        completedTasks++;
                }
                if (completedTasks == totalTasks) return i + 1;
        }

        return 0; // 예외 처리
}
