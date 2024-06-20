#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct map
{
        map(int size = 50)
        {
                table.resize(size);
        }
        int hash(string str, int size = 50)
        {
                int key = 0;

                for (char& c : str)
                        key += c - 'a';

                key %= size;
                return key;
        }

        void insert(string key, int value)
        {
                table[hash(key)].push_back(make_pair(key, value));
        }

        int get(string key)
        {
                int ret = -1;
                int hkey = hash(key);

                for (auto p : table[hkey])
                {
                        if (p.first == key)
                        {
                                ret = p.second;
                                break;
                        }
                }

                return ret;
        }

        vector<vector<pair<string, int>>> table;

};

struct Node
{
        vector<Node*> childs;
        string value;

        void Push(Node& str)
        {
                int cnt = 0;
                for (int i = 0; i < str.value.size(); i++)
                {
                        if (str.value[i] != value[i])
                                cnt++;

                        if (cnt > 1)
                                return;
                }

                if (cnt == 1)
                        childs.push_back(&str);
        }
};
vector<Node> nodes;
vector<bool> visited;
map m;

const int INF = 100000000;
int answer = INF;
void DFS(Node& node, string& target, int depth)
{
        if (node.value == target)
        {
                answer = min(answer, depth);
                return;
        }

        int key = m.get(node.value);
        visited[key] = true;


        for (auto child : node.childs)
        {
                int ckey = m.get(child->value);
                if (visited[ckey] == false)
                        DFS(*child, target, depth + 1);
        }


        visited[key] = false;
}

int solution(string begin, string target, vector<string> words) {
        visited.resize(words.size());

        words.push_back(begin);
        words.push_back(target);

        for (int i = 0; i < words.size(); i++)
        {
                Node node;
                node.value = words[i];

                nodes.push_back(node);
                m.insert(words[i], i);
        }

        for (int i = 0; i < words.size(); i++)
        {
                for (int j = 0; j < words.size(); j++)
                {
                        nodes[i].Push(nodes[j]);
                }
        }

        DFS(nodes[m.get(begin)], target, 0);

        //    for (auto c : nodes[0].childs)
          //      cout << c->value << " ";
        return answer == INF ? 0 : answer;
}

// begin -> target
// hit -> cog
// words = {hot, dot, dog, lot, log, cog}
// answer = hit -> hot -> dot -> dog -> cog

// hit -> hot -> dot -> lot, dog -> log, cog

// 모든 문자열을 순회하여 트리로 만들기 (무한 루프를 막기 위해 방문여부 체크)
// DFS를 이용해서 모든 자식노드 순회
// target을 만나면 end


