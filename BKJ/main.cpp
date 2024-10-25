#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
bool Check(int a, int b, int base, bool isPlus, int& result)
{
        int thirdDigit = 0;
        int secondDigit = (a / 10) + (b / 10);
        int firstDigit = (a % 10) + (b % 10);

        if (isPlus)
        {
                if (firstDigit / base > 0)
                {
                        secondDigit++;
                        firstDigit -= base;
                }

                if (secondDigit / base > 0)
                {
                        thirdDigit++;
                        secondDigit -= base;
                }
        }
        else
        {
                secondDigit = (a / 10) - (b / 10); // 무조건 0보다 큼
                firstDigit = (a % 10) - (b % 10);
                if (firstDigit < 0) {
                        secondDigit--;
                        firstDigit = (firstDigit % base + base) % base;
                }
        }

        int total = thirdDigit * 100 + secondDigit * 10 + firstDigit;

        if (result == -1)
                result = total;

        return total == result;
}

bool check(string exp, int base, int& result)
{
        int idx = 0;
        int a = exp[idx] - '0';
        if (exp[idx + 1] != ' ')
        {
                a *= 10;
                a += exp[++idx] - '0';
        }
        idx += 2;

        bool isPlus = exp[idx] == '+' ? true : false;

        idx += 2;

        int b = exp[idx] - '0';
        if (exp[idx + 1] != ' ')
        {
                b *= 10;
                b += exp[++idx] - '0';
        }

        idx += 4;

        result = exp[idx] - '0';
        if (exp[idx] == 'X')
                result = -1;
        idx++;
        while (idx < exp.size())
        {
                result = result * 10 + exp[idx++] - '0';
        }


        //    string test = isPlus ? "+" : "-";
         //  cout << "\nEXP : " << exp << "\n";
        //    cout << "Phasing : " << a << " " << test << " " << b << " = " << result << "\n";
        return Check(a, b, base, isPlus, result);
}


vector<string> solution(vector<string> expressions) {

        set<int> bases;
        for (int i = 0; i <= 9; i++)
                bases.insert(i);

        int bigNum = 0;
        for (string exp : expressions)
                for (char& c : exp)
                        if (c >= '0' && c <= '9')
                                bigNum = max(bigNum, c - '0');

        for (int i = bigNum; i >= 0; i--)
                bases.erase(i);


        for (int base : bases)
        {
                for (string& exp : expressions)
                {
                        if (exp.back() == 'X')
                                continue;

                        int temp = 0;
                        if (!check(exp, base, temp))
                        {
                                bases.erase(base);
                                break;
                        }
                }
        }


        vector<string> answer;
        for (string& exp : expressions)
        {
                if (exp[exp.size() - 1] != 'X')
                        continue;

                set<int> rets;
                for (int base : bases)
                {
                        int ret = 0;
                        check(exp, base, ret);
                        rets.insert(ret);
                }

                exp.pop_back();
                if (rets.size() == 1)
                        exp += to_string(*rets.begin());
                else
                        exp += '?';


                answer.push_back(exp);
        }

        return answer;
}

// 여러 수식을 입력 받을 때
// 해당 수식들이 몇진법으로 만들어진 것인지 찾아야함 (2~ 9진법)
// 우선 수식들 중 가장 큰 수를 찾고 해당 수 보다 작은 수는 가능한 진법 목록에서 삭제
// 살아 남은 진법들을 이용해서 수식 풀이 -> 불가능 하다면 삭제
// 마지막 까지 살아남은 진법들로 문제 풀이 -> 정답이 하나로 동일하면 해당 수를 입력, 
// 정답이 여러개가 나오면 ?를 입력