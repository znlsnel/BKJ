#include <string>
#include <vector>

using namespace std;

bool winnerCheck(vector<string>& b, char c)
{
        if (b[0][0] == c && b[0][0] == b[1][1] && b[1][1] == b[2][2])
                return true;
        if (b[0][2] == c && b[0][2] == b[1][1] && b[1][1] == b[2][0])
                return true;

        for (int i = 0; i < 3; i++)
        {
                if (b[i][0] == c && b[i][0] == b[i][1] && b[i][1] == b[i][2])
                        return true;
                if (b[0][i] == c && b[0][i] == b[1][i] && b[1][i] == b[2][i])
                        return true;
        }
        return false;
}

int solution(vector<string> board) {

        int oCnt = 0;
        int xCnt = 0;
        for (string& b : board)
        {
                for (char& c : b)
                {
                        if (c == 'O')
                                oCnt++;
                        else if (c == 'X')
                                xCnt++;
                }
        }
        bool isOWinner = winnerCheck(board, 'O');
        bool isXWinner = winnerCheck(board, 'X');

        // 나올 수 없는 경우를 찾아서 0을 반환,  없다면 1을 반환
        // 1. 둘다 이긴 경우
        // 2. O의 개수가 X보다 2이상 클 경우 
        // 3. O의 개수가 X보다 작을 경우 
        // 4. O가 이겼는데 개수가 같을 경우
        // 5. X가 이겼는데 O의 개수가 더 많을 경우

        if (oCnt < xCnt || oCnt > xCnt + 1)
                return 0;
        if (isOWinner && isXWinner)
                return 0;
        if (isOWinner && oCnt == xCnt)
                return 0;
        if (isXWinner && oCnt > xCnt)
                return 0;

        return 1;
}