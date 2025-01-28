using System;
using System.Collections.Generic;

public class Solution {
        public int[] solution(int[] progresses, int[] speeds) {


                int[] times = new int[speeds.Length];
                for (int i = 0; i < progresses.Length; i++) {
                        times[i] = (100 - progresses[i]) / speeds[i];
                        if ((100 - progresses[i]) % speeds[i] > 0)
                                times[i]++;
                }


                List<int> ans = new List<int>();

                int maxNum = times[0];
                int cnt = 1;
                for (int i = 1; i < times.Length; i++)
                {
                        if (times[i] > maxNum)
                        {
                                maxNum = times[i];
                                ans.Add(cnt);
                                cnt = 1;
                        }
                        else
                                cnt++;

                }
                ans.Add(cnt);

                int[] answer = new int[ans.Count];
                for (int i = 0; i < ans.Count; i++)
                        answer[i] = ans[i];


                return answer;
        }
}

// 5 10 1 1 1 20
// v v        v
