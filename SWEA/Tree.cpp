#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	int n;
	Node* left = nullptr;
	Node* right = nullptr;
} Node;

void preorder(Node* node)
{
	if (node == nullptr)
		return;

	cout << node->n << " ";
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node* node)
{
	if (node == nullptr)
		return;

	inorder(node->left);
	cout << node->n << " ";
	inorder(node->right);
}

void postorder(Node* node)
{
	if (node == nullptr)
		return;

	postorder(node->left);
	postorder(node->right);
	cout << node->n << " ";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Node* root;
	int V; //정점의 개수
	cin >> V;
	vector<Node> node(V + 1);
	vector<int> idx_v(V * 2);
	for (int i = 0; i < (V - 1) * 2; i++)
		cin >> idx_v[i];

	for (int i = 0; i < idx_v.size() - 1; i+= 2)
	{
		int parent = idx_v[i];
		int child = idx_v[i + 1];
		node[parent].n = parent;
		node[child].n = child;
		if (node[parent].left == nullptr)
			node[parent].left = &node[child];
		else
			node[parent].right = &node[child];
	}

	root = &node[idx_v[0]];
	cout << "preorder: ";
	preorder(root);
	cout << '\n';
	cout << "inorder: ";
	inorder(root);
	cout << '\n';
	cout << "postorder: ";
	postorder(root);
	cout << '\n';

	
	return 0;
}
