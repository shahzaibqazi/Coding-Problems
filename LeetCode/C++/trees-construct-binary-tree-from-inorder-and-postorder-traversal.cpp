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
                                 vector<int>& postorder, int post_start, int post_end) {
        if (in_end < in_start || post_end < post_start) {   // no node left
            return nullptr;
        }
        
        // Last element in Postorder should be root
        int rootVal = postorder[post_end];
        TreeNode* root = new TreeNode(rootVal);
        
        if (in_start == in_end || post_start == post_end) {
            return root;    
        }
        
        int root_idx = findIndex(inorder, rootVal);
        int n_left = root_idx - in_start;   // #nodes in left branch
        int n_right = in_end - root_idx;    // #nodes in right branch
        
        root->left = buildTreeRecursive(inorder, in_start, root_idx-1, 
                                        postorder, post_start, post_end-n_right-1);
        root->right = buildTreeRecursive(inorder, root_idx+1, in_end, 
                                         postorder, post_start+n_left, post_end-1);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeRecursive(inorder, 0, inorder.size()-1, 
                                  postorder, 0, postorder.size()-1);
    }
};
