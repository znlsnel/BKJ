#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101010

vector<int> g[MAX];
vector<int> rev[MAX];
int chk[MAX];
vector<int> dfn;
int scc[MAX];
vector< vector<int> > comp;
int n, m;

void dfs(int v) {
	chk[v] = 1;
	for (auto i : g[v]) {
		if (chk[i]) continue;
		dfs(i);
	}
	dfn.push_back(v);
}

void dfs_rev(int v, int color) {
	scc[v] = color;
	comp.back().push_back(v);
	for (auto i : rev[v]) {
		if (scc[i]) continue;
		dfs_rev(i, color);
	}
}

void getSCC() {
	fill(chk, chk + MAX, 0);
	fill(scc, scc + MAX, 0);

	dfn.clear();
	comp.clear();

	for (int i = 1; i <= n; i++) {
		if (!chk[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	int pv = 0;
	for (auto i : dfn) {
		if (scc[i]) continue;
		comp.push_back(vector<int>());
		dfs_rev(i, ++pv);
	}
}

void init() {
	for (int i = 0; i < MAX; i++) g[i].clear(), rev[i].clear();
}

void solve() {
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		rev[b].push_back(a);
	}
	getSCC();
	int ans = 0;
	for (auto& i : comp) {
		bool flag = 0;
		for (auto& j : i) {
			for (auto& k : rev[j]) {
				if (scc[j] == scc[k]) continue;
				flag = 1;
			}
		}
		ans += !flag;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
}