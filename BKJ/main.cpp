using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {

        int IDX(int y, int x, int n) { return y * n + x; }
        (int, int) IDX(int idx, int n) { return (idx / n, idx % n); }


        int Find(int[] parents, int a)
        {
                if (parents[a] == a)
                        return a;

                return parents[a] = Find(parents, parents[a]);
        }

        void Union(int[] parents, int a, int b)
        {
                a = Find(parents, a);
                b = Find(parents, b);

                if (a <= b)
                        parents[b] = a;
                else
                        parents[a] = b;
        }

        int[] dy = { 0, 0, 1, -1 };
        int[] dx = { 1, -1, 0, 0 };
        int BFS(int[, ] land, int[] parents, int h, int y, int x, ref List<(int, int, int)> costs)
        {
                int n = land.GetLength(0);

                Queue<(int, int)> q = new Queue<(int, int)>();
                q.Enqueue((y, x));
                while (q.Count > 0)
                {
                        var(cy, cx) = q.Dequeue();

                        for (int i = 0; i < 4; i++)
                        {
                                var(ny, nx) = (cy + dy[i], cx + dx[i]);

                                // ny, nx가 land 안에 있지 않다면 건너 뛰기
                                if (ny < 0 || nx < 0 ||
                                        ny >= land.GetLength(0) || nx >= land.GetLength(1))
                                        continue;

                                int cIdx = IDX(cy, cx, n);
                                int nIdx = IDX(ny, nx, n);

                                // 이미 연결되어 있다면 건너 뛰기
                                if (Find(parents, cIdx) == Find(parents, nIdx))
                                        continue;


                                // 높이가 너무 높으면 건너 뛰기
                                int cost = Math.Abs(land[cy, cx] - land[ny, nx]);
                                if (cost > h) {
                                        costs.Add((cIdx, nIdx, cost));
                                        continue;
                                }

                                Union(parents, cIdx, nIdx);

                                q.Enqueue((ny, nx));
                        }
                }
                int idx = IDX(y, x, n);

                return Find(parents, idx);
        }

        public int solution(int[, ] land, int height) {

                int n = land.GetLength(0);
                int m = land.GetLength(1);

                int[] parents = new int[90001];
                for (int i = 0; i < n * m; i++)
                        parents[i] = i;

                List<(int, int, int)> costs = new List<(int, int, int)>();
                HashSet<int> area = new HashSet<int>();

                for (int i = 0; i < land.GetLength(0); i++)
                        for (int j = 0; j < land.GetLength(1); j++)
                                area.Add(BFS(land, parents, height, i, j, ref costs));
                Dictionary<(int, int), int> dic = new Dictionary<(int, int), int>();

                foreach(var tpl in costs)
                {
                        var(stt, dst, cost) = tpl;
                        stt = Find(parents, stt);
                        dst = Find(parents, dst);

                        if (stt == dst)
                                continue;

                        if (stt > dst)
                        {
                                int tmp = stt;
                                stt = dst;
                                dst = tmp;
                        }

                        if (dic.ContainsKey((stt, dst)))
                                dic[(stt, dst)] = Math.Min(dic[(stt, dst)], cost);
                        else
                                dic[(stt, dst)] = cost;
                }

                costs.Clear();
                foreach(var d in dic)
                {
                        var(stt, dst) = d.Key;
                        costs.Add((stt, dst, d.Value));
                }

                // 비용을 기준으로 오름차순 정렬

                costs.Sort((a, b) = > a.Item3.CompareTo(b.Item3));


                int answer = 0;
                foreach(var c in costs)
                {
                        var(stt, dst, cost) = c;
                        stt = Find(parents, stt);
                        dst = Find(parents, dst);
                        if (stt == dst)
                                continue;

                        Union(parents, stt, dst);
                        answer += cost;
                }


                return answer;
        }
}

// 최대 크기 300 * 300 = 90000

// 높이가 3 이하인 경우 사다리 없이 이동 가능 
// BFS를 통해 갈 수 있는 곳들 끼리 연결 (Union - Find)
// 사다리가 필요한 곳을 List로 보관 (List<(start, dest, 비용)> 
// 이후 List를 dictionary로 보관 Dictionary<(start, dest), 최소 비용>
