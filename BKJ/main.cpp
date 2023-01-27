#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 5000;

int n, m, id, CN, cycleN[MAX], seqN[MAX];
vector<int> v[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int>> SCC;

int DFS(int curr) {
	seqN[curr] = ++id;
	S.push(curr);

	int parent = seqN[curr];
	for (int next : v[curr]) 
	{
		if (seqN[next] == 0) 
			parent = min(parent, DFS(next));

		else if (!finished[next]) 
			parent = min(parent, seqN[next]);
	}

	if (parent == seqN[curr]) {
		vector<int> scc;
		while (1) {
			int t = S.top();
			S.pop();
			scc.push_back(t);
			finished[t] = true;
			cycleN[t] = CN;
			if (t == curr) break;
		}

		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
		CN++;
	}

	return parent;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	while (1) {
		cin >> n;
		if (n == 0) break;
		cin >> m;

		id = 0;
		SCC.clear();
		CN = 0;
		while (!S.empty()) S.pop();
		for (int i = 0; i < n; ++i)	v[i].clear();

		fill(finished, finished + MAX, false);
		fill(seqN, seqN + MAX, 0);
		fill(cycleN, cycleN + MAX, -1);


		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			v[a - 1].push_back(b - 1);
		}

		for (int i = 0; i < n; ++i)
			if (seqN[i] == 0) DFS(i);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < v[i].size(); ++j) 
			{
				int currCycle = cycleN[i];
				int nextNode = cycleN[v[i][j]];

				// 다음 노드가 현재 사이클에 포함되지 않는다면
				if (currCycle != nextNode) SCC[currCycle].clear();
			}
		}

		sort(SCC.begin(), SCC.end());

		for (int i = 0; i < SCC.size(); ++i) {
			if (!SCC[i].empty()) {
				for (int j = 0; j < SCC[i].size(); ++j)
					cout << SCC[i][j] + 1 << ' ';
			}
		}
		cout << '\n';

	}
	return 0;
}