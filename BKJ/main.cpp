#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> strs;
string origin = "ACFJMNRT";

void DFS(vector<bool> visited = vector<bool>(origin.size()), string str = "")
{
        if (str.size() == origin.size())
        {
                strs.push_back(str);
                return;
        }

        for (int i = 0; i < origin.size(); i++)
        {
                if (visited[i] == true)
                        continue;
                visited[i] = true;
                str += origin[i];

                DFS(visited, str);

                visited[i] = false;
                str.pop_back();
        }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
        strs.resize(0);
        origin = "ACFJMNRT";

        DFS();

        int answer = 0;
        for (string str : strs)
        {
                bool success = true;
                for (string d : data)
                {
                        char a = d[0];
                        char b = d[2];

                        int idxA, idxB;
                        for (int i = 0; i < str.size(); i++)
                        {
                                if (str[i] == a)
                                        idxA = i;
                                if (str[i] == b)
                                        idxB = i;
                        }

                        int dist = abs(idxA - idxB) - 1;
                        int targetDist = d[4] - '0';

                        success = (d[3] == '=' && dist == targetDist) ||
                                (d[3] == '<' && dist < targetDist) ||
                                (d[3] == '>' && dist > targetDist);

                        if (success == false)
                                break;
                }

                if (success)
                        answer++;
        }

        return answer;
}