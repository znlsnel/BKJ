#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
        vector<string> answer;
        set<pair<long long, long long>> pos;

        for (int i = 0; i < line.size() - 1; i++) {
                for (int j = i + 1; j < line.size(); j++) {
                        long long AD_BC = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
                        if (AD_BC != 0) {
                                double x = ((double)line[i][1] * line[j][2] - (double)line[i][2] * line[j][1]) / AD_BC;
                                double y = ((double)line[i][2] * line[j][0] - (double)line[i][0] * line[j][2]) / AD_BC;

                                if (x - (long long)x == 0 && y - (long long)y == 0) {
                                        pos.insert({ x, y });
                                }
                        }
                }
        }

        long long min_x = 9223372036854775807;
        long long max_x = -9223372036854775808;
        long long min_y = 9223372036854775807;
        long long max_y = -9223372036854775808;

        for (const auto& p : pos) {
                min_x = min(p.first, min_x);
                min_y = min(p.second, min_y);
                max_x = max(p.first, max_x);
                max_y = max(p.second, max_y);
        }

        for (long long y = min_y; y <= max_y; y++) {
                string tmp = "";
                for (long long x = min_x; x <= max_x; x++) {
                        tmp += ".";
                }
                answer.push_back(tmp);
        }

        for (const auto& p : pos) {
                answer[abs(p.second - max_y)][abs(p.first - min_x)] = '*';
        }

        return answer;
}