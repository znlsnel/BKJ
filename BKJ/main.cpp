#include <string>
#include <vector>
#include <set>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
        vector<string> aaa;
        string answer = "";
        char nowAlpha = sentence[0];
        int ttt = nowAlpha - 'a';
        int prevCheckIdx = -1;
        string tempString = "";
        set<char> finalCheck;
        // 예외 처리
        if (ttt >= 0 && ttt < 26)// 소문자
        {
                int tempCnt = 0;
                for (int i = 0; i < sentence.length(); i++)
                {
                        if (nowAlpha == sentence[i])
                        {
                                tempCnt += 1;
                        }
                }
                if (tempCnt != 2)
                        return "invalid";
        }

        for (int i = 0; i < sentence.length(); i++)
        {
                nowAlpha = sentence[i];
                ttt = nowAlpha - 'a';
                if (ttt >= 0 && ttt < 26)// 소문자
                {
                        int nowAlphaCnt = 0;
                        char tempAlpha, tempAlpha2;
                        int lastIdx = 0;
                        for (int j = i; j < sentence.length(); j++)
                        {
                                tempAlpha = sentence[j];
                                if (tempAlpha == nowAlpha)
                                {
                                        nowAlphaCnt += 1;
                                        lastIdx = j;
                                }
                        }
                        if (nowAlphaCnt == 1) //규칙1
                        {
                                if (finalCheck.find(nowAlpha) != finalCheck.end())
                                {
                                        return "invalid";
                                }
                                else
                                {
                                        finalCheck.insert(nowAlpha);
                                }
                                if (i - 1 <= prevCheckIdx)
                                {
                                        return "invalid";
                                }
                                if (i - 1 < 0 || i + 1 >= sentence.length())
                                {
                                        return "invalid";
                                }
                                else
                                {
                                        tempString = tempString.substr(0, tempString.length() - 1);
                                        if (tempString != "")
                                        {
                                                aaa.push_back(tempString);
                                        }
                                        tempString = "";
                                        tempString += sentence[i - 1];
                                        tempString += sentence[i + 1];
                                        aaa.push_back(tempString);
                                        tempString = "";
                                }
                                i += 1;
                                prevCheckIdx = lastIdx + 1;
                        }
                        else if (nowAlphaCnt == 2) //규칙2라고 생각하기
                        {
                                // 규칙1,2가 같이 있는지 검사
                                if (finalCheck.find(nowAlpha) != finalCheck.end())
                                {
                                        return "invalid";
                                }
                                else
                                {
                                        finalCheck.insert(nowAlpha);
                                }
                                if (tempString != "")
                                {
                                        aaa.push_back(tempString);
                                }
                                int ttt2;
                                tempString = "";
                                bool flag = false;
                                for (int j = i + 1; j < lastIdx; j++)
                                {
                                        tempAlpha2 = sentence[j];
                                        ttt2 = tempAlpha2 - 'a';
                                        if (ttt2 >= 0 && ttt2 < 26)// 소문자
                                        {
                                                flag = true;
                                                break;
                                        }
                                        else
                                        {
                                                tempString += tempAlpha2;
                                        }
                                }
                                if (flag)
                                {
                                        tempString = "";
                                        char sameC = sentence[i + 2];
                                        if (finalCheck.find(sameC) != finalCheck.end())
                                        {
                                                return "invalid";
                                        }
                                        else
                                        {
                                                finalCheck.insert(sameC);
                                        }
                                        for (int j = i + 2; j < lastIdx; j += 2) // 겹쳐있다면, i+2는 전부 소문자이며 같은 문자다.
                                        {
                                                tempAlpha2 = sentence[j];
                                                if (sameC != tempAlpha2)
                                                {
                                                        return "invalid";
                                                }
                                        }
                                        for (int j = i + 1; j <= lastIdx; j += 2) // 겹쳐있다면, i+2는 전부 소문자이며 같은 문자다.
                                        {
                                                tempString += sentence[j];
                                        }
                                        if (tempString == "")
                                        {
                                                return "invalid";
                                        }
                                        aaa.push_back(tempString);
                                        tempString = "";
                                }
                                else
                                {
                                        if (tempString == "")
                                        {
                                                return "invalid";
                                        }
                                        aaa.push_back(tempString);
                                        tempString = "";
                                }
                                i = lastIdx;
                        }
                        else //규칙 무조건 1, 3개이상이므로
                        {
                                if (finalCheck.find(nowAlpha) != finalCheck.end())
                                {
                                        return "invalid";
                                }
                                else
                                {
                                        finalCheck.insert(nowAlpha);
                                }
                                tempString = tempString.substr(0, tempString.length() - 1);
                                if (tempString != "")
                                {
                                        aaa.push_back(tempString);
                                        tempString = "";
                                }
                                if (i - 1 <= prevCheckIdx)
                                {
                                        return "invalid";
                                }
                                char sameC = sentence[i];
                                for (int j = i; j <= lastIdx; j += 2) // i+2는 전부 소문자이며 같은 문자다.
                                {
                                        tempAlpha2 = sentence[j];
                                        if (sameC != tempAlpha2)
                                        {
                                                return "invalid";
                                        }
                                }
                                if (lastIdx + 1 >= sentence.length())
                                {
                                        return "invalid";
                                }
                                for (int j = i - 1; j <= lastIdx + 1; j += 2) // i+2는 전부 소문자이며 같은 문자다.
                                {
                                        tempString += sentence[j];
                                }
                                prevCheckIdx = lastIdx + 1;
                                aaa.push_back(tempString);
                                tempString = "";
                                i = lastIdx + 1;
                        }
                }
                else
                {
                        tempString += nowAlpha;
                }
        }
        if (tempString != "")
        {
                aaa.push_back(tempString);
        }
        for (int j = 0; j < aaa[0].length(); j++)
        {
                ttt = aaa[0][j] - 'a';
                if (ttt >= 0 && ttt < 26)// 소문자가 들어가면 불가능
                {
                        return "invalid";
                }
        }
        answer = aaa[0];
        for (int i = 1; i < aaa.size(); i++)
        {
                for (int j = 0; j < aaa[i].length(); j++)
                {
                        ttt = aaa[i][j] - 'a';
                        if (ttt >= 0 && ttt < 26)// 소문자가 들어가면 불가능
                        {
                                return "invalid";
                        }
                }
                answer += " " + aaa[i];
        }

        return answer;
}