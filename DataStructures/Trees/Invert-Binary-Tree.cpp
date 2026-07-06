#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* invertBinaryTree(TreeNode* root)
{
    if(!root){return nullptr;}
    swap(root->left, root->right);
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
    return root;
}

// prints tree level-order to visualize result
void printTree(TreeNode* root)
{
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* curr = q.front(); q.pop();
        cout << curr->val << " ";
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
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

    cout << "Before invert: ";
    printTree(root);

    invertBinaryTree(root);

    cout << "After invert:  ";
    printTree(root);

    return 0;
}
