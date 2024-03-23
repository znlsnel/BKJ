#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>  _map;

int _destX, _destY;
struct POS
{
	POS() {
		x = -1; y = -1; isinRange = true; distance = 0;
	}
	POS(int posX, int posY, int dst = 0) {
		x = posX;
		y = posY;
		distance = dst; 
		if (x > _destX || y > _destY || x < 0 || y < 0) {
			isinRange = false; 
		}
		else
			isinRange = true;
	}   
	  
	bool operator !=(POS other) {
		return this->x != other.x || this->y != other.y;		 
	}
	  
	bool isinRange;
	int x;
	int y;

	int distance;
};
vector<vector<bool>>  _visit;
 
int _count = 20;
int _minDistance = 100;
void DFS(POS cur)
{
	if (cur.x == _destX && cur.y == _destY)
	{ 
		if (_minDistance > cur.distance) {
			_minDistance = cur.distance; 
		} 
	}
	  
	POS downPos = POS(cur.x, cur.y + 1, cur.distance + 1);
	POS upPos = POS(cur.x, cur.y - 1, cur.distance + 1);
	POS leftPos = POS(cur.x - 1, cur.y, cur.distance + 1);
	POS rightPos = POS(cur.x + 1, cur.y, cur.distance + 1);
	  
	auto checkCanMove = [&](POS nextPos)
	{
		bool canMove = nextPos.isinRange && _map[nextPos.y][nextPos.x] && _visit[nextPos.y][nextPos.x] == false;
		if (canMove) 
		{ 
			_visit[nextPos.y][nextPos.x] = true;   
			DFS(nextPos);
			_visit[nextPos.y][nextPos.x] = false;
		}  
	};
	  
	checkCanMove(upPos); 
	checkCanMove(downPos); 
	checkCanMove(leftPos);
	checkCanMove(rightPos); 
}

int main()
{
	cin >> _destY;
	cin >> _destX;
	_map.resize(_destY, vector<int>(_destX, 0));
	_visit.resize(_destY, vector<bool>(_destX, false));
	std::string line;

	for (int i = 0; i < _destY; ++i) {
		// 한 줄씩 문자열로 입력 받음
		std::cin >> line; 
		for (int j = 0; j < _destX; ++j) {
			// 문자열의 각 문자를 정수로 변환하여 저장
			_map[i][j] = line[j] - '0';
		}
	} 

	_destX--;
	_destY--;
	_visit[0][0] = true;
	DFS(POS(0, 0));
	
	cout << _minDistance + 1; 
}