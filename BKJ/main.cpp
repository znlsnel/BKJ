#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {

        vector<bool> visited(cards.size(), false);

        vector<int> answer;
        for (int i = 0; i < cards.size(); i++)
        {
                if (visited[i])
                        continue;
                visited[i] = true;

                int size = 1;
                int idx = cards[i] - 1;
                while (visited[idx] == false)
                {
                        visited[idx] = true;
                        idx = cards[idx] - 1;
                        size++;
                }

                answer.push_back(size);
        }

        sort(answer.begin(), answer.end(), [](int A, int B) {return A > B; });
        return answer.size() == 1 ? 0 : answer[0] * answer[1];
}