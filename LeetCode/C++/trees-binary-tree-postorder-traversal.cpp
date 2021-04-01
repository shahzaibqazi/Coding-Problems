/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorderTraversalUtil(TreeNode* root, vector<int> &tree) {
        if (root) {
            postorderTraversalUtil(root->left, tree);
            postorderTraversalUtil(root->right, tree);
            tree.push_back(root->val);
        }
        
        return;        
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> tree;
        postorderTraversalUtil(root, tree);
        
        return tree;        
    }
};
