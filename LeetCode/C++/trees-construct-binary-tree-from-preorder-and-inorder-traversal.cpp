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
    int findIndex(vector<int>& vec, int val) {
        for(int idx = 0; idx < vec.size(); idx++) {
            if(vec[idx] == val)
                return idx;
        }
        return -1;  // val not found (not needed in our case)
    }
    
 
    TreeNode* buildTreeRecursive(vector<int>& inorder, int in_start, int in_end,
                                 vector<int>& preorder, int pre_start, int pre_end) {
        if (in_end < in_start || pre_end < pre_start) {   // no node left
            return nullptr;
        }
        
        // First element in Preorder should be root
        int rootVal = preorder[pre_start];
        TreeNode* root = new TreeNode(rootVal);
        
        if (in_start == in_end || pre_start == pre_end) {
            return root;    
        }
        
        // Find root in Inorder
        int root_idx = findIndex(inorder, rootVal);
        int n_left = root_idx - in_start;   // #nodes in left branch
        int n_right = in_end - root_idx;    // #nodes in right branch
        
        root->left = buildTreeRecursive(inorder, in_start, root_idx-1, 
                                        preorder, pre_start+1, pre_start+n_left);
        root->right = buildTreeRecursive(inorder, root_idx+1, in_end, 
                                         preorder, pre_end-n_right+1, pre_end);
        
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeRecursive(inorder, 0, inorder.size()-1, 
                                  preorder, 0, preorder.size()-1);        
    }
 
};
