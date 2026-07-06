#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        postorder(root->left, result);   
        postorder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};

int main() {
    // Build tree: [1, null, 2, 3]
    //     1
    //      \
    //       2
    //      /
    //     3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);        // first assign right
    root->right->left = new TreeNode(3); // then assign its left
    root->right->left->left = new TreeNode(4);
    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;  
    return 0;
}