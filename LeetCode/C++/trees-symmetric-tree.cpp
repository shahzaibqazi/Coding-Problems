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
    // Checks if two trees are symmetric identical
    bool areSymmetricIdentical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (root1 && root2) {
            return (root1->val == root2->val
                && areSymmetricIdentical(root1->left, root2->right) 
                && areSymmetricIdentical(root1->right, root2->left));
        }
        return false;
    }
    
    // Checks if the tree is symmetrical
    bool isSymmetric(TreeNode* root) {
        if(root)
            return areSymmetricIdentical(root->left, root->right);
        
        return true;
    }
};
