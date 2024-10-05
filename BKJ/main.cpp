#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 1000000000;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
        vector<vector<int>> edge(n + 1);

        // 간선 정보 입력
        for (auto& e : edge_list) {
                edge[e[0]].push_back(e[1]);
                edge[e[1]].push_back(e[0]);
        }

        // 자기 자신으로 이동하는 것도 가능함
        for (int i = 1; i <= n; i++) {
                edge[i].push_back(i);
        }

        // dp[i][j] -> i시간에 j 노드에 도착했을 때 변경된 횟수의 최솟값
        vector<vector<int>> dp(k, vector<int>(n + 1, INF));
        dp[0][gps_log[0]] = 0;  // 시작점에서의 변경 횟수는 0

        for (int t = 1; t < k; t++) {
                for (int i = 1; i <= n; i++) {
                        if (dp[t - 1][i] == INF) continue;  // 이전에 도달 불가능한 경우는 패스

                        for (int next : edge[i]) {
                                int change = (next != gps_log[t]) ? 1 : 0;  // 다음 노드가 gps_log와 다르면 1번 변경
                                dp[t][next] = min(dp[t][next], dp[t - 1][i] + change);
                        }
                }
        }

        // 마지막 시간에 목적지에 도착했을 때의 최소 변경 횟수
        int answer = dp[k - 1][gps_log[k - 1]];

        return (answer == INF) ? -1 : answer;
}

int main() {
        // 예시 입력
        int n = 7;
        int m = 10;
        vector<vector<int>> edge_list = { {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}, {4, 6}, {5, 6}, {5, 7} };
        int k = 6;
        vector<int> gps_log = { 1, 2, 3, 3, 6, 7 };

        int result = solution(n, m, edge_list, k, gps_log);
        cout << "결과: " << result << endl;

        return 0;
}
