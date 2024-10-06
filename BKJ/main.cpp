#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool Compute(int a, int b, int& result, int base, bool plus)
{
        int thirdDigit = 0;
        int secondDigit = (a / 10) + (b / 10);
        int firstDigit = (a % 10) + (b % 10);

        if (plus)
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
        char p = plus ? '+' : '-';
        //   cout << "[" << base << "] " << a << " "<< p <<" " << b << " = " << total << "\n";

        if (result == -1)
                result = total;

        return total == result;
}

void Parsing(string& exprs, int& a, int& b, int& result, bool& plus)
{
        a = exprs[0] - '0';
        int next = 2;

        if (exprs[1] != ' ') {
                a = a * 10 + exprs[1] - '0';
                next++;
        }

        plus = false;
        if (exprs[next] == '+')
                plus = true;

        next += 2;

        b = exprs[next] - '0';
        if (exprs[next + 1] != ' ') {
                b = b * 10 + exprs[next + 1] - '0';
                next++;
        }

        next += 4;


        result = exprs[next] - '0';
        if (exprs[next] == 'X')
                result = -1;

        next++;
        while (next < exprs.size())
        {
                result = result * 10 + exprs[next] - '0';
                next++;
        }

        //  cout << "A : " << a << " B : " << b << " result : " << result << " plus : " << plus << "\n";
}

vector<string> solution(vector<string> expressions) {
        set<int> questions;
        set<int> bases;

        // 진법 범위 찾기
        int start = 2;
        for (int i = 0; i < expressions.size(); i++)
        {
                string& exprs = expressions[i];

                if (exprs.back() == 'X')
                        questions.insert(i);

                for (char c : exprs)
                {
                        if (c >= '2' && c <= '9') {
                                start = max(start, (c - '0') + 1);
                        }
                }
        }

        for (int i = start; i <= 9; i++)
                bases.insert(i);


        // 맞는 진법 찾기
        for (int base : bases)
        {
                for (int i = 0; i < expressions.size(); i++)
                {
                        // 문제면 패스
                        if (questions.find(i) != questions.end())
                                continue;

                        string& exprs = expressions[i];
                        int a, b, result; bool isPlus;
                        Parsing(exprs, a, b, result, isPlus);

                        if (!Compute(a, b, result, base, isPlus))
                        {
                                bases.erase(base);
                                break;
                        }
                }
        }

        // 살아남은 진법들과, 문제들을 비교하여 풀이
        // 모든 진법에서 같은 정답이 나오면 표기,
        // 다른 정답이 나오면 '?'로 정답 표기

        vector<string> answer;
        for (int q : questions)
        {
                set<int> results;
                string& exprs = expressions[q];

                for (int base : bases)
                {
                        int a, b, result; bool isPlus;
                        Parsing(exprs, a, b, result, isPlus);
                        Compute(a, b, result, base, isPlus);
                        results.insert(result);
                }

                if (results.size() > 1)
                        exprs[exprs.size() - 1] = '?';
                else
                {
                        exprs.pop_back();
                        exprs += to_string(*results.begin());
                }

                answer.push_back(exprs);
        }


        return answer;
}
