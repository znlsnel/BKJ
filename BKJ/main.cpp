#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct priority_queue
{
        priority_queue(bool b = false) : isDescOrder(b) {}

        void insert(T value)
        {
                int idx = data.size();
                data.push_back(value);

                while (idx > 0)
                {
                        int parent = (idx - 1) / 2;
                        if (!CMP(data[idx], data[parent]))
                        {
                                break;
                        }
                        swap(data[idx], data[parent]);

                        idx = parent;
                }

        }

        void pop()
        {
                if (data.empty())
                        return;

                int idx = 0;
                data[idx] = data.back();
                data.pop_back();

                while (idx < data.size())
                {
                        int left = (idx * 2) + 1;
                        int right = left + 1;

                        if (left >= data.size())
                                break;

                        if (right < data.size() && CMP(data[right], data[left]))
                                left = right;

                        if (!CMP(data[left], data[idx]))
                                break;

                        swap(data[left], data[idx]);
                        idx = left;
                }
        }

        bool CMP(const T& a, const T& b)
        {
                if (isDescOrder)
                        return *a > *b;

                else
                        return *a < *b;
        }

        T top()
        {
                return data.empty() == true ? nullptr : data[0];
        }

        bool empty()
        {
                return data.empty();
        }

        bool isDescOrder = false;
        vector<T> data;
};

struct NODE
{
        bool use = false;
        int value;

        bool operator < (NODE other)
        {
                return value < other.value;
        }

        bool operator > (NODE other)
        {
                return value > other.value;
        }

        NODE(int v) : value(v) { use = false; };
};

vector<int> solution(vector<string> operations) {
        priority_queue<NODE*> minQ;
        priority_queue<NODE*> maxQ(true);
        vector<unique_ptr<NODE>> nodes;

        for (string& str : operations)
        {
                int value = stoi(str.substr(2));

                if (str[0] == 'I')
                {
                        nodes.push_back(make_unique<NODE>(value));
                        NODE* node = nodes.back().get();

                        minQ.insert(node);
                        maxQ.insert(node);
                }
                else if (value == 1)
                {
                        while (!maxQ.empty() && maxQ.top()->use)
                                maxQ.pop();


                        if (!maxQ.empty())
                        {
                                NODE* node = maxQ.top();
                                node->use = true;
                                maxQ.pop();
                        }

                }
                else if (value == -1)
                {
                        while (!minQ.empty() && minQ.top()->use)
                                minQ.pop();

                        if (!minQ.empty())
                        {
                                NODE* node = minQ.top();
                                node->use = true;
                                minQ.pop();
                        }
                }

        }

        while (!maxQ.empty() && maxQ.top()->use == true)
                maxQ.pop();

        while (!minQ.empty() && minQ.top()->use == true)
                minQ.pop();

        int minTop = minQ.empty() ? 0 : minQ.top()->value;
        int maxTop = maxQ.empty() ? 0 : maxQ.top()->value;
        return { maxTop, minTop };
}

// ["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
// -5643

// min   -45 45 333
// max   333 45 -45