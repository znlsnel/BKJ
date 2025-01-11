#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
        int answer = 0;
        map<string, int> w, d;

        for (int i = 0; i < want.size(); i++) {
                w.insert({ want[i], number[i] });
                d.insert({ want[i], 0 });
        }

        int left = 0; int right = 10;
        for (int i = 0; i < discount.size() && i < 10; i++)
                d[discount[i]]++;


        while (true)
        {
                bool find = true;
                for (auto p : w)
                {
                        string name = p.first;
                        int cnt = p.second;

                        if (d[name] < cnt)
                        {
                                find = false;
                                break;
                        }
                }
                if (find)
                        answer++;

                if (left >= discount.size())
                        break;


                d[discount[left++]]--;
                if (right < discount.size())
                        d[discount[right++]]++;
        }



        return answer;
}