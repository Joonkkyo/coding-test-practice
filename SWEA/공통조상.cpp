#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
 
constexpr int MAX = 10000;
 
typedef struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
} Node;
 
Node nodes[MAX];
int parents_v1[MAX], parents_v2[MAX];
int idx_v1 = 0, idx_v2 = 0;
 
void init()
{
    memset(nodes, 0, sizeof(nodes));
    memset(parents_v1, 0, sizeof(parents_v1));
    memset(parents_v2, 0, sizeof(parents_v2));
    idx_v1 = 0;
    idx_v2 = 0;
}
 
Node* newNode(int n)
{
    nodes[n].key = n;
    nodes[n].left = nullptr;
    nodes[n].right = nullptr;
    nodes[n].parent = nullptr;
    return &nodes[n];
};
 
void find_v1_parents(Node* node)
{
    if (node->key == 1) return;
    parents_v1[idx_v1++] = node->parent->key;
    if (node->parent != nullptr) find_v1_parents(node->parent);
}
 
void find_v2_parents(Node* node)
{
    if (node->key == 1) return;
    parents_v2[idx_v2++] = node->parent->key;
    if (node->parent != nullptr) find_v2_parents(node->parent);
}
 
int cal_subtree_size(Node* node)
{
    int size = 1;
    queue<Node*> q;
    q.push(node);
 
    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        if (cur->left != nullptr)
        {
            q.push(cur->left);
            size++;
        }
 
        if (cur->right != nullptr)
        {
            q.push(cur->right);
            size++;
        }
    }
 
    return size;
}
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int test_case; 
    cin >> test_case;
    for (int tc = 1; tc <= 10; tc++)
    {
        init();
        int V, E, v1, v2;
        cin >> V >> E >> v1 >> v2;
 
        for (register int i = 0; i < E; i++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            if (nodes[n1].key == NULL) newNode(n1);
            if (nodes[n2].key == NULL) newNode(n2);
 
            if (nodes[n1].left == nullptr) nodes[n1].left = &nodes[n2];
            else nodes[n1].right = &nodes[n2];
            nodes[n2].parent = &nodes[n1];
        }
 
        find_v1_parents(&nodes[v1]);
        find_v2_parents(&nodes[v2]);
         
        int common_parent;
        bool flag = false;
 
        for (int i = 0; i < idx_v1; i++)
        {
            for (int j = 0; j < idx_v2; j++)
            {
                if (parents_v1[i] == parents_v2[j])
                {
                    common_parent = parents_v1[i];
                    flag = true;
                    break;
                }
            }
 
            if (flag) break;
        }
 
        cout << '#' << tc << ' ' << common_parent << ' ' << cal_subtree_size(&nodes[common_parent]) << '\n';
    }
 
    return 0;
}
