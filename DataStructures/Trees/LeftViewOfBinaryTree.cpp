/* 
The left view is the set of nodes visible when you look at the tree 
from the left side — i.e., the first node at each level.


        1          ← visible
       / \
      2   3        ← 2 is visible (3 is hidden behind it)
     / \   \
    4   5   6      ← 4 is visible (5, 6 hidden)
         \
          7        ← 7 is visible
Left view: 1 → 2 → 4 → 7

Key insight: For every level, you only want the leftmost node. The rest are blocked.

Common approaches:

BFS (level order): at each level, pick the first node from the queue
DFS (recursive): track the current depth; if it's a new max depth seen so far, this node 
is part of the left view 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

void dfs(TreeNode* root, int depth, int& maxDepth, vector<int>& result)
{
    if(!root) return;

    if(depth > maxDepth)
    {
        result.push_back(root->val);
        maxDepth = depth;
    }

    dfs(root->left,  depth + 1, maxDepth, result);
    dfs(root->right, depth + 1, maxDepth, result);
}

vector<int> leftView(TreeNode* root)
{
    vector<int> result;
    int maxDepth = -1;
    dfs(root, 0, maxDepth, result);
    return result;
}

vector<int> leftViewBFS(TreeNode* root)
{
    vector<int> result;
    if(!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int levelSize = q.size();

        for(int i = 0; i < levelSize; i++)
        {
            TreeNode* node = q.front(); q.pop();

            if(i == 0) result.push_back(node->val);  // first node in level

            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return result;
}

int main()
{
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //         \
    //          7
    TreeNode* root = new TreeNode(1);
    root->left           = new TreeNode(2);
    root->right          = new TreeNode(3);
    root->left->left     = new TreeNode(4);
    root->left->right    = new TreeNode(5);
    root->right->right   = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    cout << "DFS: ";
    vector<int> dfsView = leftView(root);
    for(int v : dfsView) cout << v << " ";  // 1 2 4 7
    cout << "\n";

    cout << "BFS: ";
    vector<int> bfsView = leftViewBFS(root);
    for(int v : bfsView) cout << v << " ";  // 1 2 4 7
    cout << "\n";

    return 0;
}