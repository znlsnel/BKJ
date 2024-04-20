#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


static int N, M;

class Node
{
public:
	Node* childs[26];
	bool isLeaf;
	Node() : isLeaf(false)
	{
		fill(childs, childs + 26, nullptr);
	}
	~Node() {
		for (auto& child : childs)
			delete child;
	}

	void insert(const char* key)
	{
		if (*key == 0)
			isLeaf = true;
		else
		{
			int next_index = *key - 'a';
			if (childs[next_index] == nullptr)
				childs[next_index] = new Node();

			childs[next_index]->insert(key + 1);
		}

	}

	Node* find(const char* key)
	{
		if (*key == 0)
			return this;

		int next_index = *key - 'a';

		if (childs[next_index] == nullptr)
			return nullptr;
		return childs[next_index]->find(key + 1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	Node* root = new Node();

	while (N--)
	{
		char text[501];
		cin >> text;
		root->insert(text);
	}

	int count = 0;

	while (M--)
	{
		char text[501];
		cin >> text;
		Node* result = root->find(text);

		if (result && result->isLeaf)
			count++;
	}
	cout << count << "\n";

} 
 
