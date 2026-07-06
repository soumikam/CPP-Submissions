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

bool isMirror(TreeNode* left, TreeNode* right)
{
    if(!left && !right){return true;}
    if(!left || !right){return false;}

    return (left->val == right->val && 
        isMirror(left->left,right->right) && 
        isMirror(left->right,right->left));
}

bool isSymmetric(TreeNode* root)
{
    return isMirror(root->left, root->right);
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


    isSymmetric(root);
    return 0;
}