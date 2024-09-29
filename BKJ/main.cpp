#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
        int answer = 1e8;
        int w_size = weak.size();

        for (int i = 0; i < w_size - 1; ++i) {
                weak.push_back(weak[i] + n);
        }

        sort(dist.begin(), dist.end()); // next_permutation 사용 위해 정렬

        do {
                for (int i = 0; i < w_size; ++i) {
                        int start = weak[i];
                        int end = weak[i + w_size - 1];

                        for (int j = 0; j < dist.size(); ++j) {
                                start += dist[j]; // 친구 이동

                                if (start >= end) { // 모든 지점 점검 마쳤을 경우
                                        answer = min(answer, j + 1);
                                        break;
                                }

                                // 외벽 점검을 마치지 않았지만 더이상 이동할 수 없으면 다음 지점으로 이동
                                for (int z = i + 1; z < i + w_size; ++z) {
                                        if (weak[z] > start) {
                                                start = weak[z];
                                                break;
                                        }
                                }
                        }
                }
        } while (next_permutation(dist.begin(), dist.end()));

        if (answer == 1e8) return -1;

        return answer;
}