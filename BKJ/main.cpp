#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
        unordered_set<string> gemKinds(gems.begin(), gems.end());
        unordered_map<string, int> gemCount;

        for (string& gem : gems)
                gemKinds.insert(gem);

        int requireGemCnt = gemKinds.size();
        int foundGemCnt = 0;
        int start = 0; int end = 0;
        int min_start = 0; int min_end = gems.size();

        while (end < gems.size())
        {
                if (gemCount[gems[end]] == 0)
                        foundGemCnt++;

                gemCount[gems[end]]++;
                end++;

                while (foundGemCnt == requireGemCnt)
                {
                        if (min_end - min_start > end - start)
                        {
                                min_end = end;
                                min_start = start;
                        }

                        gemCount[gems[start]]--;
                        if (gemCount[gems[start]] == 0)
                                foundGemCnt--;

                        start++;
                }
        }



        return { min_start + 1, min_end };
}