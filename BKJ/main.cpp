#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001
using namespace std;

// 강한 결합 요소 ( SCC - Strongly Connected Component ) 알고리즘

bool finished[MAX];		// SCC에 포함되어 있는 애들은 체크하여 중복 제거
int seqID[MAX], id;		// 각 노드에 순서번호를 매겨서 root 노드를 체크함
vector<int> v[MAX];		// 각 정점이 담길 그래프
vector<vector<int>> SCC;	// SCC가 담길 vector

stack<int> s;			// stack을 활용하여 scc 추출

int dfs(int node)
{
	int start = seqID[node] = ++id;
	s.push(node);

	for (size_t i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];

		if (seqID[next] == 0)
			start = min(start, dfs(next));

		else if (finished[next] == false)
			start = min(start, seqID[next]);
	}

	if (start == seqID[node])
	{

		vector<int> scc;
		while (true)
		{
			int _node = s.top();
			s.pop();
			finished[_node] = true;
			scc.push_back(_node);

			if (_node == node)
				break;
			
		}

		SCC.push_back(scc);
	}
	return start;
}

bool com(vector<int>& a, vector<int>& b)
{
	return a[0] < b[0];
}

int main()
{
	int V, E;
	cin >> V >> E;

	int s, d;
	for (int i = 0; i < E; i++)
	{
		cin >> s >> d;
		v[s].push_back(d);
	}
	
	for (int i = 1; i <= V; i++)
	{
		if (seqID[i] == 0) dfs(i);
	}
	
	// 오름차순 정렬
	for (int i = 0; i < SCC.size(); i++)
		sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end(), com);
	
	cout << SCC.size()<< "\n";
	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j = 0; j < SCC[i].size(); j++)
			cout << SCC[i][j] << " ";
		cout << "-1\n";
	}

	return 0;
}
