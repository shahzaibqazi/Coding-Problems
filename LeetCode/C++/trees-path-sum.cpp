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
    bool hasPathSumRecursive(TreeNode* root, int targetSum, int sum) {
        int sum_local;
        sum += root->val;
        
        if (!root->left && !root->right) {  // leaf node case
            return (sum == targetSum ? true : false);
        }
        bool hasPathSum_l = false, hasPathSum_r = false;
        sum_local = sum;

        hasPathSum_l = root->left ? hasPathSumRecursive(root->left, targetSum, sum) : false;
        sum = sum_local;    // resetting static sum value to the local sum of node

        hasPathSum_r = root->right ? hasPathSumRecursive(root->right, targetSum, sum) : false;
        sum = sum_local;

        return hasPathSum_l || hasPathSum_r;         
    }
        
    bool hasPathSum(TreeNode* root, int targetSum) {
        return (root ? hasPathSumRecursive(root, targetSum, 0) : false);
    }
};
