#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

static int N;

struct priorityQueue
{
        // left = cur * 2 + 1;
        // right = cur * 2  + 2;
        // parent = (cur - 1) / 2;

        void push(int i)
        {
                arr[size] = i;
                siftUP(size);
                size++;
        }

        void siftUP(int i)
        {
                int parent = (i - 1) / 2;

                if (arr[parent] > arr[i]) {
                        std::swap<int>(arr[parent], arr[i]);
                        siftUP(parent); 
                } 
                
        }

        void siftDown(int i)
        {
                int left = i * 2 + 1;
                int right = left + 1;

                if (left >= arr.size() || left >= size) 
                        return;

                if ((right < arr.size() || right >= size) && arr[left] > arr[right]) {
                        left = right; 
                }

                if (arr[left] < arr[i]) {
                        std::swap<int>(arr[left], arr[i]);
                        siftDown(left); 
                } 
        }

        int top()
        {
                return size ? arr[0] : -1;
        }

        void pop()
        {
                arr[0] = arr[--size];
                siftDown(0); 
        }


        int size = 0;
        vector<int> arr;
};

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);

        cin >> N;
        int a;
         
        priorityQueue q;
        q.arr.resize(N);

        for (int i = 0; i < N; i++) {
                cin >> a;
                q.push(a); 
        }

        for (int i = 0; i < N; i++)
        {
                cout << q.top() << "\n";
                q.pop();
        }

         
} 

