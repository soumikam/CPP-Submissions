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
        postorder(root->left, result);   // 1. visit left
        result.push_back(root->val);   // 2. visit root
        postorder(root->right, result);  // 3. visit right
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
    cout << "]" << endl;  // Expected: [1,3,2]

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string>
// #include <sstream>
// using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int v) : val(v), left(nullptr), right(nullptr){};
// };

// // Build tree from level-order input like: 1 null 2 3
// TreeNode* buildTree(vector<string>& nodes)
// {
//     if (nodes.empty() || nodes[0] == "null") return nullptr;

//     TreeNode* root = new TreeNode(stoi(nodes[0]));
//     queue<TreeNode*> q;
//     q.push(root);

//     int i = 1;
//     while (!q.empty() && i < nodes.size())
//     {
//         TreeNode* curr = q.front(); q.pop();

//         // left child
//         if (i < nodes.size() && nodes[i] != "null")
//         {
//             curr->left = new TreeNode(stoi(nodes[i]));
//             q.push(curr->left);
//         }
//         i++;

//         // right child
//         if (i < nodes.size() && nodes[i] != "null")
//         {
//             curr->right = new TreeNode(stoi(nodes[i]));
//             q.push(curr->right);
//         }
//         i++;
//     }
//     return root;
// }

// class Solution
// {
// public:
//     void inorder(TreeNode* root, vector<int>& res)
//     {
//         if(root == nullptr){return;}
//         inorder(root->left, res);
//         res.push_back(root->val);
//         inorder(root->right, res);
//     }

//     vector<int> inorderTraversal(TreeNode* root)
//     {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }
// };

// int main()
// {
//     cout << "Enter tree nodes level-order (use 'null' for missing nodes):" << endl;
//     cout << "Example: 1 null 2 3" << endl;
//     cout << "Input: ";

//     string line;
//     getline(cin, line);

//     // parse input into tokens
//     vector<string> nodes;
//     stringstream ss(line);
//     string token;
//     while (ss >> token)
//         nodes.push_back(token);

//     TreeNode* root = buildTree(nodes);

//     Solution sol;
//     vector<int> result = sol.inorderTraversal(root);

//     cout << "Inorder Output: [";
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i];
//         if (i != result.size() - 1) cout << ",";
//     }
//     cout << "]" << endl;

//     return 0;
// }