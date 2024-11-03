#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
	if (v1[1] == v2[1])
		return v1[0] < v2[0];
	return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {

	int answer = 0;

	sort(targets.begin(), targets.end(), cmp);

	int e = targets[0][1];

	answer++;

	for (int i = 1; i < targets.size(); i++) {
		if (targets[i][0] < e) {
			continue;
		}
		else {
			answer++;
			e = targets[i][1];
		}

	}

	return answer;
}