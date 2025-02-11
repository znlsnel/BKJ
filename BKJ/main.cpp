using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
        HashSet<int> trap = new HashSet<int>();
        List<(int, int)>[] road;
        int[] dists;

        void OnTrap(int num)
        {


        }

        void Dijkstra(int start, int end)
        {
                // 노드, 비용
                SortedSet<(int, int)> pq = new SortedSet<(int, int)>();
                pq.Add((start, 0));
                dists[start] = 0;

                while (pq.Count > 0)
                {
                        var(cur, cost) = pq.First();
                        pq.Remove((cur, cost));

                        for (int i = 0; i < road[cur].Count; i++)
                        {
                                int nxt = road[cur][i].Item1;
                                int nCost = road[cur][i].Item2;

                                if (dists[nxt] <= cost + nCost)
                                        continue;

                                dists[nxt] = cost + nCost;
                                pq.Add((nxt, nCost));

                        }
                }

        }
        int MAXVALUE = 10000000;


        public int solution(int n, int start, int end, int[, ] roads, int[] traps) {


                dists = new int[n + 1];
                Array.Fill(dists, MAXVALUE);
                road = new List<(int, int)>[n + 1];

                foreach(int a in traps)
                        trap.Add(a);

                for (int i = 1; i <= n; i++)
                        road[i] = new List<(int, int)>();


                for (int i = 0; i < roads.GetLength(0); i++)
                {
                        int s = roads[i, 0];
                        int e = roads[i, 1];
                        int c = roads[i, 2];


                        road[s].Add((e, c));
                }

                Dijkstra(start, end);

                return dists[end] == MAXVALUE ? -1 : dists[end];
        }
}