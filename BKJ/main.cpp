#include <iostream>
#include <vector>
#include <queue>

// 아스키코드
// 소문자 ( 97 ~ 122 )
// 대문자 ( 65 ~ 90 )
// 입력 받은 문자를 0 ~ 51까지의 index 번호로 바꿔줌
#define chgId(char) char = char > 90 ? char - 71 : char - 65
#define MAX  52

using namespace std;

// 모든 노드가 담길 vector
vector<int> v[MAX];

// 각 간선의 최대 유량 정보
int limit[MAX][MAX];

// 각 간선의 현재 유량 정보
int flow[MAX][MAX];

// 부모 노드 정보
int parent[MAX];

int MaxFlow()
{
	// A : 0,      Z : 25 
	int result = 0, start = 0, end = 25;

	while (true)
	{
		// parent를 -1로 초기화
		fill(parent, parent + MAX, -1);
		queue<int> q;
		q.push(start);

		while (!q.empty())
		{
			int curr = q.front();
			q.pop();

			for (int i = 0; i < v[curr].size(); i++)
			{
				int next = v[curr][i];

				// 흘려 보낼 공간이 남아있고 이미 검색된 노드가 아닐때
				if (limit[curr][next] > flow[curr][next] && parent[next] == -1)
				{
					q.push(next);
					// 부모노드 세팅
					parent[next] = curr;
				}
			}
		}
	
		// parent[end]가 -1이라는 것은 end로 흘려보낼 공간이 남아있지 않다는 것
		// 즉 검색이 완료되었다는 것을 의미함
		if (parent[end] == -1) return result;

		// end로 가는 경로로 흘려 보낼 수 있는 용량을 구함
		int min = 1000;
		for (int i = end; i != start; i = parent[i])
		{
			// 각 간선의  최대 유량 - 현재 유량 = 남은 공간
			int remain = limit[parent[i]][i] - flow[parent[i]][i];
			if (min > remain) min = remain;
		}

		// 현재 흐르고 있는 양 체크
		for (int i = end; i != start; i = parent[i])
		{
			flow[parent[i]][i] += min;
			flow[i][parent[i]] -= min;
		}
		result += min;
	}

}

int main()
{
	int N;
	char start, dest;
	int capacity;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> start >> dest >> capacity;
		chgId(start);
		chgId(dest);

		v[start].push_back(dest);
		v[dest].push_back(start);

		limit[start][dest] += capacity;
		limit[dest][start] += capacity;
	}
	cout << MaxFlow();

	return 0;
}