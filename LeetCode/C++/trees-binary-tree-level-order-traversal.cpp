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
private:
    
public:    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tree;
        
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
        
            while(!q.empty()) {
                vector<int> level;
                int q_size = q.size();

                for(int i=0; i < q_size; i++) {
                    TreeNode *node = q.front(); 
                    level.push_back(node->val);

                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                    q.pop();
                }
                tree.push_back(level);
            }
        }
        
        return tree;    
    }
};
