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
    // Mirror-flips whole tree
    void flipTree(TreeNode* root) {
        if (root) {
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;

            if(root->left)
                flipTree(root->left);
            if(root->right)
                flipTree(root->right);
        }
    }
    
    // Checks if two trees are identical
    bool areIdentical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }

        if (root1 && root2) {
            return (root1->val == root2->val
                && areIdentical(root1->left, root2->left) 
                && areIdentical(root1->right, root2->right));
        }
        return false;
    }
    
    // Checks if two trees are identical
    bool isSymmetric(TreeNode* root) {
        if(root) {
            flipTree(root->left);   // 
            bool result = areIdentical(root->left, root->right);
            return result;
        }
        return true;
    }
};
