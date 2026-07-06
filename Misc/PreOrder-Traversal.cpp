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

void preorder(TreeNode* root, vector<int>& result)
{
    if(root==nullptr){return;}
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

vector<int> result(TreeNode* root)
{
    vector<int> result;
    preorder(root, result);
    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);

    vector<int> preorder = result(root);
    for (int i=0; i< preorder.size(); i++)
    {
        cout << preorder[i] << " " ;
    }
    return 0;
}
