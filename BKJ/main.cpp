#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

vector<ll> heights;
ll P, Q;
vector<ll> prefixSum;

// 특정 높이 h로 평탄화할 때의 비용 계산 (누적합 이용)
ll getCost(ll h) {
        int idx = lower_bound(heights.begin(), heights.end(), h) - heights.begin();

        ll lowerSum = prefixSum[idx];  // h 이하인 모든 블록의 총합
        ll upperSum = prefixSum.back() - lowerSum;  // h 초과 블록의 총합

        ll lowerCost = h * idx - lowerSum;  // h 이하 블록 올리는 비용
        ll upperCost = upperSum - h * (heights.size() - idx);  // h 초과 블록 내리는 비용

        return lowerCost * P + upperCost * Q;
}

// 삼분 탐색으로 최소 비용 찾기
ll ternarySearch(ll left, ll right) {
        while (right - left > 2) {  // 삼분 탐색 진행
                ll mid1 = left + (right - left) / 3;
                ll mid2 = right - (right - left) / 3;

                ll cost1 = getCost(mid1);
                ll cost2 = getCost(mid2);

                if (cost1 < cost2) right = mid2;
                else left = mid1;
        }

        ll minCost = LLONG_MAX;
        for (ll h = left; h <= right; h++) {
                minCost = min(minCost, getCost(h));
        }
        return minCost;
}

long long solution(vector<vector<int>> land, int p, int q) {
        P = p, Q = q;

        // 1. 높이 배열 만들기
        for (const auto& row : land) {
                for (int h : row) {
                        heights.push_back(h);
                }
        }

        // 2. 높이 정렬 후 누적합 계산
        sort(heights.begin(), heights.end());
        prefixSum.resize(heights.size() + 1, 0);

        for (size_t i = 0; i < heights.size(); i++) {
                prefixSum[i + 1] = prefixSum[i] + heights[i];
        }

        // 3. 삼분 탐색으로 최소 비용 구하기
        return ternarySearch(heights.front(), heights.back());
}
