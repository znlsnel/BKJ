#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements)
{
        set<int> s;

        for (int len = 1; len <= elements.size(); len++)
        {
                for (int i = 0; i < elements.size(); i++)
                {
                        int num = 0;
                        int j = i;

                        for (j = i; j < i + len; j++)
                                num += elements[j % elements.size()];

                        s.insert(num);
                }
        }

        for (int i = 0; i < elements.size(); i++)
        {
                int num = 0;
                for (int j = i; j < i + elements.size(); j++)
                {
                        num += elements[j % elements.size()];
                        s.insert(num);
                }

        }

        return s.size();
}