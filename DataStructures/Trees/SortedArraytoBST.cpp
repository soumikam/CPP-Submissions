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


TreeNode* build(vector<int> nums, int left, int right)
{
    if(left > right){return nullptr;}

    int mid = left + (right - left)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, left, mid-1);
    root->right = build(nums, mid+1, right);
    return root;
}

TreeNode* buildBSTFromArray(vector<int>nums)
{
    return build(nums, 0, nums.size()-1);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << "\n";
}
 
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = buildBSTFromArray(nums);
    printLevelOrder(root);  // 4 2 6 1 3 5 7
    return 0;
}