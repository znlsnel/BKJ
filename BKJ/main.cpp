#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int, int> edge;
long MAXLONG = 2000000000;

void myFunction(int size);
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true)
	{
		int size;
		cin >> size;
		if (size)
			myFunction(size);
		else
			break;
	}

	return 0;
}

static int TestCount = 0;
void myFunction(int size)
{
	TestCount++;

	vector<vector<int>> map(size);
	vector<int> resultCosts(size * size, MAXLONG);
	vector<bool> visited(size * size, false); 

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			int cost;
			cin >> cost;
			map[i].push_back(cost);
		}
	}

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0}; 

	resultCosts[0] = map[0][0];
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	// cost, start;
	pq.push(make_pair(resultCosts[0], 0));
	  
	while (pq.size())
	{
		int startID = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();
		 
		for (int i = 0; i < 4; i++)
		{
			int nextX = dx[i] + (startID % size);
			int nextY = dy[i] + (startID / size);
			if (nextX >= size || nextX < 0 || nextY >= size || nextY < 0) 
				continue; 
			 
			int nextID = nextY * size + nextX;
			int nextCost = map[nextY][nextX]; 
			 
			if (resultCosts[nextID] > nextCost + curCost) {
				resultCosts[nextID] = nextCost + curCost;
				pq.push(make_pair(resultCosts[nextID], nextID));
			}
		}
	}
	 
	cout << "Problem " << TestCount << ": " << resultCosts[size * size - 1] << "\n";
}

