#include <string>
#include <vector>
#include <iostream>

using namespace std;

int _kep = 0;
int _price = 0;
vector<int> _rates;

void dfs(vector<vector<int>>& users, vector<int>& emoticons) {
        if (_rates.size() < emoticons.size())
        {
                for (int i = 10; i <= 40; i += 10)
                {
                        _rates.push_back(i);
                        dfs(users, emoticons);
                        _rates.pop_back(); // rate vector 재사용을 위한 pop
                }
                return;
        }

        int tmp_Kep = 0;
        int tmp_price = 0;

        for (int i = 0; i < users.size(); i++)
        {
                int p = 0;
                for (int j = 0; j < emoticons.size(); j++)
                {
                        if (users[i][0] > _rates[j])
                                continue;

                        p += emoticons[j] * ((100 - _rates[j]) / 100.0f);
                }

                // i번 유저가 총 구매할 비용
                if (p >= users[i][1])
                        tmp_Kep++;
                else
                        tmp_price += p;
        }

        if (tmp_Kep > _kep)
        {
                _kep = tmp_Kep;
                _price = tmp_price;
        }
        else if (tmp_Kep == _kep && tmp_price > _price)
        {
                _price = tmp_price;
        }

}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {

        dfs(users, emoticons);
        return { _kep, _price };
}
