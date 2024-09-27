#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 현재 구조물이 유효한지 확인하는 함수
bool isValid(vector<vector<int>>& build) {
        for (auto& b : build) {
                int x = b[0], y = b[1], a = b[2];
                if (a == 0) { // 기둥
                        if (y == 0 || // 바닥 위에 있거나
                                find(build.begin(), build.end(), vector<int>{x - 1, y, 1}) != build.end() || // 왼쪽에 보가 있거나
                                find(build.begin(), build.end(), vector<int>{x, y, 1}) != build.end() || // 오른쪽에 보가 있거나
                                find(build.begin(), build.end(), vector<int>{x, y - 1, 0}) != build.end()) { // 아래에 기둥이 있거나
                                continue;
                        }
                        else {
                                return false;
                        }
                }
                else { // 보
                        if (find(build.begin(), build.end(), vector<int>{x, y - 1, 0}) != build.end() || // 왼쪽 아래에 기둥이 있거나
                                find(build.begin(), build.end(), vector<int>{x + 1, y - 1, 0}) != build.end() || // 오른쪽 아래에 기둥이 있거나
                                (find(build.begin(), build.end(), vector<int>{x - 1, y, 1}) != build.end() &&
                                        find(build.begin(), build.end(), vector<int>{x + 1, y, 1}) != build.end())) { // 양쪽에 보가 있거나
                                continue;
                        }
                        else {
                                return false;
                        }
                }
        }
        return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
        vector<vector<int>> build;

        for (auto& frame : build_frame) {
                int x = frame[0], y = frame[1], a = frame[2], b = frame[3];

                if (b == 1) { // 설치
                        build.push_back({ x, y, a });
                        if (!isValid(build)) { // 설치 후 유효하지 않으면 취소
                                build.pop_back();
                        }
                }
                else { // 제거
                        build.erase(remove(build.begin(), build.end(), vector<int>{x, y, a}), build.end());
                        if (!isValid(build)) { // 제거 후 유효하지 않으면 다시 설치
                                build.push_back({ x, y, a });
                        }
                }
        }

        sort(build.begin(), build.end()); // 최종 결과를 정렬
        return build;
}
