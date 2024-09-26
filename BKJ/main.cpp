#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
        int idx;
        int x;
        int y;
        Node* left;
        Node* right;


        bool operator < (Node& other)
        {
                if (y == other.y)
                        return x < other.x;
                return y > other.y;
        }

        void insert(Node& node)
        {
                if (x > node.x)
                {
                        if (left == nullptr)
                                left = &node;
                        else
                                left->insert(node);
                }
                else
                {
                        if (right == nullptr)
                                right = &node;
                        else
                                right->insert(node);
                }
        }


        void Preorder(vector<int>& answer, int cnt = 1)
        {
                answer.push_back(idx + 1);

                if (left != nullptr)
                        left->Preorder(answer, cnt);

                if (right != nullptr)
                        right->Preorder(answer, cnt);
        }

        void Postorder(vector<int>& answer)
        {
                if (left != nullptr)
                        left->Postorder(answer);

                if (right != nullptr)
                        right->Postorder(answer);

                answer.push_back(idx + 1);
        }
};


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

        vector<Node> nodes;
        for (int i = 0; i < nodeinfo.size(); i++)
        {
                auto& node = nodeinfo[i];
                nodes.push_back(Node{ i, node[0], node[1], nullptr, nullptr });
        }

        sort(nodes.begin(), nodes.end());

        Node root = nodes[0];

        for (int i = 1; i < nodeinfo.size(); i++)
                root.insert(nodes[i]);



        vector<vector<int>> answer(2);
        root.Preorder(answer[0]);
        root.Postorder(answer[1]);

        return answer;
}
// [1,3] [2,2] [3,5] [5,3] [6,1] [7,2] [8,6] [11,5] [13,5]
// y가 높으면 부모
// x가 높으면 오른쪽 노드

// 좌표를 노드화

// 노드를 전위 순회, 후위 순회한 노드 순서 출력

// 문제의 핵심 부분 - 좌표의 노드화
// 나의 바로 윗 노드이면서 가장 가까운 노드가 나의 부모 노드

// 1. y를 기준으로 정렬
// 2. x를 기준으로 정렬
// 3. 가장가까운 y면서 가장 가까운 x인 Node를 map에서 찾기