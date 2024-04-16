#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


static int dr[] = { -1, 0, 1, 0 };
static int dc[] = { 0, 1, 0, -1 };
static int map[201][201]; 
static bool visited[201][201] = { false }; 
static vector<int> parent; 
static int N, M , sNum;
static vector<vector<pair<int, int>>> sumList;
static vector<pair<int, int>> mList;

void Union(int a, int b);
int find(int a); 
void BFS(int i, int j);

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;


static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	sNum = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0 && visited[i][j] != true)
			{
				BFS(i, j);
				sNum++;
				sumList.push_back(mList);
			}
		}
	}

	for (int i = 0; i < sumList.size(); i++)
	{
		vector<pair<int, int>> now = sumList[i];

		for (int j = 0; j < now.size(); j++)
		{
			int r = now[j].first;
			int c = now[j].second;
			int now_S = map[r][c];

			for (int d = 0; d < 4; d++)
			{
				int tempR = dr[d];
				int tempC = dc[d];
				int blenght = 0;

				while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M)
				{
					if (map[r + tempR][c + tempC] == now_S)
						break;

					else if (map[r + tempR][c + tempC] != 0)
					{
						if (blenght > 1)
							pq.push(Edge{ now_S, map[r + tempR][c + tempC], blenght });
						break;
					}
					else
						blenght++;

					if (tempR < 0)
						tempR--;
					else if (tempR > 0)
						tempR++;
					else if (tempC < 0)
						tempC--;
					else if (tempC > 0)
						tempC++;
				} 
			} 
		}
	}
	parent.resize(sNum); 

	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
	}

	int useEdge = 0;
	int result = 0;

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop(); 

		if (find(now.s) != find(now.e)) {
			Union(now.s, now.e);
			result = result + now.v;
			useEdge++;
		}

	}

	if (useEdge == sNum - 2)
		cout << result << "\n";
	else
		cout << "-1" << "\n"; 
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}

int find(int a)
{
	if (a == parent[a])
		return a;
	 
	return parent[a] = find(parent[a]);
}

void BFS(int i, int j)
{
	queue<pair<int, int>> myQueue;
	mList.clear();
	myQueue.push(make_pair(i, j));
	mList.push_back(make_pair(i, j));
	visited[i][j] = true;
	map[i][j] = sNum;

	while (!myQueue.empty())
	{
		int r = myQueue.front().first;
		int c = myQueue.front().second;
		myQueue.pop();

		for (int d = 0; d < 4; d++)
		{
			int tempR = dr[d];
			int tempC = dc[d];

			auto isInBox = [&]() { return r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M; };
			while (isInBox())
			{
				bool isVisited = visited[r + tempR][c + tempC];
				bool island = map[r + tempR][c + tempC] != 0;
				if (isVisited == false && island)
				{
					int now_i = r + tempR;
					int now_j = c + tempC;
					map[now_i][now_j] = sNum;
					visited[now_i][now_j] = true;
					mList.push_back(make_pair(now_i, now_j));
					myQueue.push(make_pair(now_i, now_j));
				}
				else
					break;
				
				if (tempR < 0)
					tempR--;
				else if (tempR > 0)
					tempR++;
				else if (tempC < 0)
					tempC--;
				else if (tempC > 0)
					tempC++;
			}


		}

	}

}