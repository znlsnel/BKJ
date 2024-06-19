#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct priority_queue
{
        //   0
        //  1 2 
        // 3 4
        // 아래에서 올라가는 방식
        void push(int value)
        {
                v.push_back(value);

                int i = v.size() - 1;

                while (i > 0)
                {
                        // 부모노드 -> -1 / 2
                        int parent = (i - 1) / 2;
                        if (v[parent] <= v[i])
                                break;

                        int t = v[i];
                        v[i] = v[parent];
                        v[parent] = t;

                        i = parent;
                }
        }

        int top()
        {
                if (v.empty())
                        return -1;

                return v[0];
        }

        // 가장 뒤의 값을 앞으로 옮기고 pop_back -> 내려가면서 정렬
        void pop()
        {
                v[0] = v.back();
                v.pop_back();

                int i = 0;

                while (i < v.size() - 1)
                {
                        int left = i * 2 + 1;
                        int right = left + 1;

                        if (left >= v.size())
                                break;

                        if (right >= v.size())
                                right = left;

                        if (v[left] > v[right])
                                left = right;

                        if (v[i] > v[left])
                        {
                                int t = v[i];
                                v[i] = v[left];
                                v[left] = t;
                        }

                        i = left;
                }
        }

        bool empty()
        {
                return v.empty();
        }
        vector<int> v;
};

void heapSort(vector<int>& c)
{
        int answer = 0;

        priority_queue pq;

        for (int n : c)
                pq.push(n);

        for (int i = 0; i < c.size(); i++)
        {
                c[i] = pq.top();
                pq.pop();
        }
}

vector<int> merge(vector<int>& a, vector<int>& b)
{
        vector<int> result;

        int id_a = 0;
        int id_b = 0;
        while (id_a < a.size() && id_b < b.size())
        {
                int next = -1;

                if (a[id_a] > b[id_b])
                        next = b[id_b++];
                else
                        next = a[id_a++];

                result.push_back(next);
        }

        while (id_a < a.size())
                result.push_back(a[id_a++]);

        while (id_b < b.size())
                result.push_back(b[id_b++]);

        return result;
}
void mergeSort(vector<int>& c)
{
        if (c.size() <= 1)
                return;

        size_t mid = c.size() / 2;

        vector<int> a(c.begin(), c.begin() + mid);
        vector<int> b(c.begin() + mid, c.end());

        mergeSort(a);
        mergeSort(b);

        c = merge(a, b);
}

int solution(vector<int> c) {
        int answer = 0;

        //  heapSort(c);
        mergeSort(c);
        //sort(c.begin(), c.end());

        for (int i = 0; i < c.size(); i++)
        {
                int n = c.size() - i;
                if (c[i] >= n)
                {
                        answer = n;
                        break;
                }
        }

        return answer;
}

// 0 1 4 5 6
// c.size() - i == 4일 때
// c[i] >= 4 여야하며
// 

