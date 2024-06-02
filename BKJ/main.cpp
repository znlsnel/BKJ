#include <string>
#include <iostream>
#include <vector>

using namespace std;



struct Pos
{
        int x;
        int y;

        Pos operator +(Pos other)
        {
                Pos r;
                r.x = x + other.x;
                r.y = y + other.y;
                return r;
        }

        bool operator == (Pos other)
        {
                return x == other.x && y == other.y;
        }

        int Length(Pos other)
        {
                return abs(other.x - x) + abs(other.y - y);
        }
};

static int N, M, K;
static Pos dst;
string answer;


void DFS(Pos pos, string str)
{
        if (answer.size() > 0 ||
                pos.Length(dst) > K - str.size() ||
                pos.x >= N || pos.x < 0 ||
                pos.y >= M || pos.y < 0)
                return;

        if (str.size() == K) {
                if (pos == dst)
                        answer = str;

                return;
        }

        DFS(pos + Pos{ 1, 0 }, str + 'd');
        DFS(pos + Pos{ 0, -1 }, str + 'l');
        DFS(pos + Pos{ 0, 1 }, str + 'r');
        DFS(pos + Pos{ -1, 0 }, str + 'u');
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
        N = n; M = m; K = k;
        dst = Pos{ r - 1, c - 1 };

        int remain = dst.Length(Pos{ x - 1, y - 1 });
        if ((K - remain) % 2 != 0 || remain > k) {
                answer = "impossible";
        }
        else
                DFS(Pos{ x - 1, y - 1 }, "");



        return answer;
}

