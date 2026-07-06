#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

int maxDepth(TreeNode* root) 
{
    if (root == nullptr) return 0;
    int left  = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(3);

    cout << "Depth is " << maxDepth(root) << endl;
    return 0;
}
