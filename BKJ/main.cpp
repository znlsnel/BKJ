#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(vector<vector<int>>& key, vector<vector<int>>& lock, int n, int y, int x)
{
        for (int i = 0; i < lock.size(); i++)
                for (int j = 0; j < lock[i].size(); j++)
                        if (lock[i][j] == key[i + n + y][j + n + x])
                                return false;

        return true;
}

void Rotate(vector<vector<int>>& key)
{
        int n = key.size();
        vector<vector<int>> ret(n, vector<int>(n));

        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        ret[i][j] = key[j][n - 1 - i];

        key = ret;
}



bool solution(vector<vector<int>> k, vector<vector<int>> lock) {

        int n = lock.size();
        int m = k.size();

        vector<vector<int>> key(n * 3, vector<int>(n * 3));
        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        key[i + n][j + n] = i >= m || j >= m ? 0 : k[i][j];

        for (int i = 0; i < 4; i++)
        {
                for (int i = -n + 1; i < n; i++)
                        for (int j = -n + 1; j < n; j++)
                                if (check(key, lock, n, i, j))
                                        return true;

                Rotate(key);
        }

        return false;
}
