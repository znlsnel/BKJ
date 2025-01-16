#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(string word) {

        vector<int> pow(5);
        pow[4] = 1;
        for (int i = 3; i >= 0; i--)
                pow[i] = pow[i + 1] * 5 + 1;

        map<char, int> idx;
        idx.insert({ 'A', 0 });
        idx.insert({ 'E', 1 });
        idx.insert({ 'I', 2 });
        idx.insert({ 'O', 3 });
        idx.insert({ 'U', 4 });
        idx.insert({ ' ', 0 });

        int answer = word.size();
        while (word.size() < 5)
                word += ' ';

        for (int i = 0; i < word.size(); i++)
        {
                answer += pow[i] * idx[word[i]];
        }
        return answer;
}
/*
AAAAA AAAAAU -> AAAE -> AAAEA -> AAAEU -> AAAI

AAAAA = 5
AAAAE = 6 1
AAAAI = 7 2
AAAAO = 8 3
AAAAU = 9 4

AAAA -> 4
AAAE = 10 6
AAAI = 16 12
AAAO = 22 18
AAAU = 28 24

AAA = 3
AAE = 34 31
AAI = 65 62 */