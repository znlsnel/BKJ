#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {

        int cnt = 0;
        int zero = 0;

        while (s.size() > 1)
        {
                int c = 0;
                for (int i = 0; i < s.size(); i++)
                {
                        if (s[i] == '1')
                                c++;
                }

                // cout << c << " : ";
                string next = "";
                int num = c;
                for (int i = 2; num > 0; i *= 2) {
                        if (num % i == i / 2)
                        {
                                next = '1' + next;
                                num -= i / 2;
                        }
                        else
                                next = '0' + next;

                }
                //    cout << next << "\n";

                zero += (s.size() - c);
                cnt++;

                s = next;
        }



        return { cnt, zero };
}