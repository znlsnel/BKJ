#include <string>
#include <vector>
#include <stack>    

using namespace std;

vector<int> solution(vector<int> numbers) {
        vector<int> answer(numbers.size());
        stack<int> s;

        for (int i = numbers.size() - 1; i >= 0; i--)
        {

                while (true)
                {
                        if (s.empty()) {
                                answer[i] = -1;
                                break;
                        }

                        else if (s.top() > numbers[i]) {
                                answer[i] = s.top();
                                break;
                        }

                        s.pop();
                }


                s.push(numbers[i]);
        }
        return answer;
}


//  9 1 4 3 4  6  2
// -1 4 6 4 6 -1 -1

// ->
// 
// 
