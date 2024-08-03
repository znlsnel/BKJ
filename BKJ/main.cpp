#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(vector<int> A, vector<int> B) {

        sort(A.begin(), A.end(), [](int& a, int& b) {return a > b; });
        sort(B.begin(), B.end(), [](int& a, int& b) {return a > b; });

        int answer = 0;
        for (int idx_a = 0, idx_b = 0; idx_a < A.size(); idx_a++)
        {
                int numA = A[idx_a];
                int numB = B[idx_b];

                if (numA < numB)
                {
                        answer++;
                        idx_b++;
                }
        }
        return answer;
}
