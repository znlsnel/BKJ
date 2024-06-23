#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> empties;
vector<vector<pair<int, int>>> puzzles;
bool visit[51][51];
int answer = 0;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int N;

vector<pair<int, int>> repos_zero(vector<pair<int, int>> pos) {//위치 백테의 기준값을 0,0으로 변환 반환
        int min_i = N;
        int min_j = N;
        for (int i = 0; i < pos.size(); i++) {
                min_i = min_i > pos[i].first ? pos[i].first : min_i;
                min_j = min_j > pos[i].second ? pos[i].second : min_j;
        }

        for (int i = 0; i < pos.size(); i++) {
                pos[i].first -= min_i;
                pos[i].second -= min_j;
        }
        return pos;
}

vector<pair<int, int>> bfs(vector<vector<int>>& map, int value, int i, int j) {//해당 map에서 값에 맞는 위치를 벡터에 저장 반환 
        visit[i][j] = true;
        vector<pair<int, int>> v;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        v.push_back(make_pair(i, j));

        while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
                        if (visit[ny][nx] || map[ny][nx] != value)continue;
                        visit[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                        v.push_back(make_pair(ny, nx));
                }
        }
        return v;
}

// 1 2 
// 3 4

// 0,0 0,1
// 1,0 1,1

// -> 1,0 0,0
//    1,1 0,1
void rot(vector<pair<int, int>>& pos) {//시계방향 90도 회전
        int row = 0;
        for (int i = 0; i < pos.size(); i++) {
                row = max(row, pos[i].first);
        }

        for (int i = 0; i < pos.size(); i++) {
                int y = pos[i].first;
                int x = pos[i].second;
                pos[i].first = x;
                pos[i].second = row - y;
        }
}

void matching() {
        vector<bool> puzzle_visit(puzzles.size(), false);

        for (vector<pair<int, int>> empty : empties)
        {
                for (int puzzle_idx = 0; puzzle_idx < puzzles.size(); puzzle_idx++)
                {
                        if (puzzle_visit[puzzle_idx])
                                continue; //이미 사용한 퍼즐이면 pass

                        vector<pair<int, int>> puzzle = puzzles[puzzle_idx];

                        if (empty.size() != puzzle.size())
                                continue; //퍼즐 조각 개수와 빈 영역의 칸 수가 같아야함

                        bool flag = false;
                        for (int r = 0; r < 4; r++)
                        {
                                int k = 0;

                                for (int i = 0; i < empty.size(); i++)
                                {//퍼즐과 빈칸 위치 비교
                                        for (int j = 0; j < puzzle.size(); j++)
                                        {
                                                if (empty[i].first == puzzle[j].first && empty[i].second == puzzle[j].second)
                                                {
                                                        k++;
                                                        continue;
                                                }
                                        }
                                }
                                if (k != empty.size()) {// 같은 위치인 갯수가 현재 빈칸의 칸수와 같지 않으면 90도 회전 후 다시 비교
                                        rot(puzzle);
                                        continue;
                                }
                                //해당 위치에 퍼즐 조각을 채울 수 있기때문에 정보갱신 후 회전, 퍼즐 조각의 for문을 break
                                answer += empty.size();
                                puzzle_visit[puzzle_idx] = true;
                                flag = true;
                                break;
                        }
                        if (flag)break;
                }
        }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
        N = game_board.size();
        //빈 공간 나누기 + (0,0) 기준으로 위치 변환
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (game_board[i][j] == 0 && !visit[i][j])
                                empties.push_back(repos_zero(bfs(game_board, 0, i, j)));
                }
        }
        //퍼즐조각 나누기 + (0,0) 기준으로 위치 변환
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (table[i][j] == 1 && !visit[i][j])
                                puzzles.push_back(repos_zero(bfs(table, 1, i, j)));
                }
        }
        matching();
        return answer;
}