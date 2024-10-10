#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
        int answer = 0;
        sort(data.begin(), data.end(), [](vector<int> a, vector<int>b) {
                return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
                });
        int upV, downV, tempUp, tempDown; //실제로 비교하는 변수, 높이가 변하기 전까지 값을 저장할 변수
        for (int i = 0; i < data.size(); i++)
        {
                upV = pow(2, 31) - 1, downV = 0;
                tempUp = upV, tempDown = downV;
                for (int j = i + 1; j < data.size(); j++)
                {
                        if (data[j - 1][0] != data[j][0])
                        { // 높이가 변하는 경우 값을 갱신
                                upV = tempUp;
                                downV = tempDown;
                        }
                        if (data[j][1] == data[i][1] || data[i][0] == data[j][0])
                        {
                                continue;
                        }
                        else if (data[j][1] > data[i][1])
                        {
                                if (upV >= data[j][1])
                                {
                                        answer += 1;
                                }
                                tempUp = min(tempUp, data[j][1]);
                        }
                        else if (data[j][1] < data[i][1])
                        {
                                if (downV <= data[j][1])
                                {
                                        answer += 1;
                                }
                                tempDown = max(tempDown, data[j][1]);
                        }
                }
        }
        return answer;
}