#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;


static int N;

class Node
{
public:
	bool isRoot = false;
	Node* left;
	Node* right; 
	char c = ' ';

	void Preorder(vector<char>* result = new vector<char>())
	{
		// root
		result->push_back(c);

		if (left) 
			left->Preorder(result); 
		
		if (right)
			right->Preorder(result);

		if (isRoot) {
			for (char a : *result)
				cout << a;
			cout << "\n";
		}
	}

	void Inorder(vector<char>* result = new vector<char>())
	{

		if (left)
			left->Inorder(result);

		result->push_back(c);

		if (right)
			right->Inorder(result);

		if (isRoot) {
			for (char a : *result)
				cout << a;
			cout << "\n";
		}
	}

	void Postorder(vector<char>* result = new vector<char>())
	{
		if (left)
			left->Postorder(result);

		if (right)
			right->Postorder(result);

		result->push_back(c); 

		if (isRoot) {
			for (char a : *result)
				cout << a;
			cout << "\n";
		}
	} 


};

vector<Node> tree;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tree.resize(N);

	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		int rootIndex = root - 'A';
		int leftIndex = left != '.' ? left - 'A' : -1;
		int rightIndex = right != '.' ? right - 'A' : -1;
		tree[rootIndex].c = root;

		if (leftIndex > 0) {
			tree[rootIndex].left = &tree[leftIndex];
			tree[rootIndex].left->c = left;
		}
		if (rightIndex > 0)
		{
			tree[rootIndex].right = &tree[rightIndex]; 
			tree[rootIndex].right->c = right;
		}
	} 
	tree[0].isRoot = true;

	tree[0].Preorder();
	tree[0].Inorder();
	tree[0].Postorder();

} 
 
