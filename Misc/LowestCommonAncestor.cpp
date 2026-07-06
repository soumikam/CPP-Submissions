#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || root == p || root == q)
    {
        return root;
    }

    TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;  // p and q on opposite sides → root is LCA
    return left ? left : right;       // return whichever side found something
}

int main()
{
    //        3
    //       / \
    //      5   1
    //     / \   \
    //    6   2   8
    //       / \
    //      7   4

    TreeNode* root  = new TreeNode(3);
    root->left      = new TreeNode(5);
    root->right     = new TreeNode(1);
    root->left->left  = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(8);
    root->left->right->left  = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;        // node 5
    TreeNode* q = root->left->right->right; // node 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    // Expected: 5

    return 0;
}