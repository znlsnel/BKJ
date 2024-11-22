#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {

        sort(data.begin(), data.end(), [&](auto& A, auto& B) {
                if (A[col - 1] == B[col - 1])
                        return A[0] > B[0];
                return A[col - 1] < B[col - 1];
                });


        int answer = 0;
        for (int i = row_begin - 1; i < row_end; i++)
        {
                int S_i = 0;
                for (int& n : data[i])
                        S_i += n % (i + 1);

                answer ^= S_i;
        }

        return answer;
}