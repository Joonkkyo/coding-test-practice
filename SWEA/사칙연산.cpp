#include <iostream>
#include <vector>
using namespace std;
 
constexpr int MAX = 1000;
 
typedef struct Node {
    bool is_num;
    int n;
    Node* left = nullptr;
    Node* right = nullptr;
} Node;
 
Node nodes[MAX];
 
double dfs(Node* node)
{
    if (node->is_num) return node->n;
    switch (node->n)
    {
    case '+':
        return dfs(node->left) + dfs(node->right);
    case '-':
        return dfs(node->left) - dfs(node->right);
    case '*':
        return dfs(node->left) * dfs(node->right);
    case '/':
        return dfs(node->left) / dfs(node->right);
    }
}
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    for (int tc = 1; tc <= 10; tc++)
    {
        int N;
        cin >> N;
 
        for (int i = 0; i < N; i++)
        {
            int idx;
            char str[10];
            int left, right;
            cin >> idx;
            cin >> str;
 
            if (str[0] >= '0' && str[0] <= '9')
            {
                nodes[idx].is_num = true;
                int num = 0;
                for (int i = 0; str[i]; i++)
                {
                    num *= 10;
                    num += str[i] - '0';
                }
 
                nodes[idx].n = num;
            }
 
            else
            {
                cin >> left >> right;
                nodes[idx].is_num = false;
                nodes[idx].n = str[0];
                nodes[idx].left = &nodes[left];
                nodes[idx].right = &nodes[right];
            }
        }
 
        cout << '#' << tc << ' ' << dfs(&nodes[1]) << '\n';
    }
     
    return 0;
}
