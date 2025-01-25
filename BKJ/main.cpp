using System;
using System.Collections.Generic;

public class Solution {
        public int solution(string skill, string[] skill_trees) {
                int answer = 0;

                HashSet<char> d = new HashSet<char>();
                foreach(char c in skill)
                        d.Add(c);

                foreach(string tree in skill_trees)
                {
                        List<char> list = new List<char>();
                        foreach(char c in tree)
                        {
                                if (d.Contains(c))
                                        list.Add(c);
                        }

                        bool flag = true;
                        for (int i = 0; i < list.Count; i++)
                        {
                                if (list[i] != skill[i])
                                {
                                        flag = false;
                                        break;
                                }
                        }
                        if (flag)
                                answer++;

                }

                return answer;
        }
}