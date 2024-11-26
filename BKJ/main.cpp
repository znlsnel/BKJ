#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calculate(long long a, long long b, char oper) {
        if (oper == '+')
                return a + b;
        else if (oper == '-')
                return a - b;
        else if (oper == '*')
                return a * b;
}

long long solution(string expression) {
        long long answer = 0;
        vector<char> oper = { '*', '+', '-' };
        vector<long long> num;
        vector<char> operators;

        int val = 0;

        for (int i = 0; i < expression.length(); i++) {
                if (expression[i] >= '0' && expression[i] <= '9')
                        val = val * 10 + (expression[i] - '0');
                else {
                        num.push_back(val);
                        val = 0;

                        operators.push_back(expression[i]);
                }
        }

        num.push_back(val);

        do {
                vector<long long> temp_num = num;
                vector<char> temp_operators = operators;

                for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < temp_operators.size(); j++) {
                                if (temp_operators[j] == oper[i]) {
                                        temp_num[j] = calculate(temp_num[j], temp_num[j + 1], oper[i]);

                                        temp_num.erase(temp_num.begin() + j + 1);
                                        temp_operators.erase(temp_operators.begin() + j);

                                        j--;
                                }
                        }
                }

                if (abs(temp_num.front()) > answer)
                        answer = abs(temp_num.front());
        } while (next_permutation(oper.begin(), oper.end()));

        return answer;
}