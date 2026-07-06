#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

bool checkIfBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX)
{
    if(!root) return true;

    if(root->val <= min || root->val >= max) return false;

    return checkIfBST(root->left,  min,       root->val) &&
           checkIfBST(root->right, root->val, max);
}

int main()
{
    //       5
    //      / \
    //     3   7
    //    / \
    //   2   4
    TreeNode* root = new TreeNode(5);
    root->left      = new TreeNode(3);
    root->right     = new TreeNode(7);
    root->left->left  = new TreeNode(2);
    root->left->right = new TreeNode(4);

    cout << "Valid BST:   " << checkIfBST(root) << endl;  // 1

    // break BST — insert 6 in wrong place
    root->left->right->val = 6;
    cout << "Invalid BST: " << checkIfBST(root) << endl;  // 0

    return 0;
}