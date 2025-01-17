#include <string>
#include <vector>
#include <iostream>

using namespace std;

string itob(long long num)
{
        string ret = "";
        while (num > 0)
        {

                ret = to_string(num % 2) + ret;
                num /= 2;
        }

        return ret;
}

long long btoi(string num)
{
        long long ret = 0;

        for (int i = 0; i < num.size(); i++)
        {
                ret *= 2;
                ret += num[i] - '0';
        }
        return ret;


}

vector<long long> solution(vector<long long> numbers) {
        vector<long long> answer;

        for (auto num : numbers)
        {
                string bit = itob(num);

                // bit중에 0이 있다면 가장 오른쪽의 0을 1로 바꾼 수 (1개 차이)
                // bit중에 0이 없다면 가장 왼쪽의 0을 1로 바꾸고 그 다음 1을 0으로 바꿈 (2개 차이)

                int idx = -1;
                for (int i = bit.size() - 1; i >= 0; i--)
                {
                        if (bit[i] == '0')
                        {
                                idx = i;
                                break;
                        }
                }

                // 1개로 해결 가능
                if (idx != -1)
                {
                        bit[idx] = '1';
                        if (idx < bit.size() - 1)
                                bit[idx + 1] = '0';
                }
                else
                {
                        bit[0] = '0';
                        bit = "1" + bit;
                }
                answer.push_back(btoi(bit));


        }

        return answer;
}
//  11111
// 101111