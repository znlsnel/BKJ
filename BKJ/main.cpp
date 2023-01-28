#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 100001

using namespace std;

int id, d[MAX]; //구역 번호는 0~n-1번까지
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;
int cycle[MAX];
int inDegree[MAX];

int dfs(int x) 
{
	d[x] = id++;
	s.push(x);
	int parent = d[x];

	for (int i = 0; i < a[x].size(); i++) 
	{
		int y = a[x][i];

		if (d[y] == -1) 
			parent = min(parent, dfs(y));

		else if (!finished[y]) 
			parent = min(parent, d[y]);
	}
	if (parent == d[x]) 
	{
		vector<int>scc;
		while (1) 
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			cycle[t] = SCC.size();
			finished[t] = true;
			if (t == x) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return parent;
}

int main() {
	int t;
	cin >> t;

	while (t--) 
	{
		int n, m;
		cin >> n >> m;

		//Init
		SCC.clear();
		fill(d, d + MAX, -1);
		fill(inDegree, inDegree + MAX, 0);
		fill(finished, finished + MAX, false);
		fill(cycle, cycle + MAX, -1);

		for (int i = 0; i < n; i++) 
		{
			a[i].clear();
		}

		for (int i = 0; i < m; i++) 
		{
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
		}

		for (int i = 0; i < n; i++) 
		{
			if (d[i] == -1) dfs(i);
		}

		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < a[i].size(); j++) 
			{
				int y = a[i][j];
				if (cycle[i] != cycle[y]) 
				{
					++inDegree[cycle[y]];
				}

			}
		}

		int count = 0;
		int num = -1;
		for (int i = 0; i < SCC.size(); i++) 
		{
			if (inDegree[i] == 0) 
			{
				num = i;
				count++;
			}
		}

		if (count == 1) 
		{
			for (int i = 0; i < SCC[num].size(); i++) 
			{
				printf("%d\n", SCC[num][i]);
			}
		}

		else 
		{
			printf("Confused\n");
		}
		printf("\n");
	}
	/*cout<<"InDegree : "<<endl;
	  for(int i=0; i<SCC.size(); i++){
	    cout<<inDegree[i]<<' ';
	  }
	  cout<<"\nEND"<<endl;*/
}