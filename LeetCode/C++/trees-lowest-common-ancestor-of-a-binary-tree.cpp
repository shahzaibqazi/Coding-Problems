/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void populateNodeAncestors(TreeNode* root, TreeNode* node, stack<TreeNode*> &st, bool &found) {
        
        if (!root) {
            return;
        }
        
        if (root == node) {
            found = true;
        }
        else {
            if (!found) {
                populateNodeAncestors(root->left, node, st, found);
            }       
            if (!found) {
                populateNodeAncestors(root->right, node, st, found);
            }
        }
 
        if (found) {
            st.push(root);
        }       
        return;
    }
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca;
        stack<TreeNode*> st_p, st_q;
        bool found_p = false, found_q = false;
        
        populateNodeAncestors(root, p, st_p, found_p);  // populate ancestor nodes of p in stack
        populateNodeAncestors(root, q, st_q, found_q);  // populate ancestor nodes of q in stack
        
        auto p_t = st_p.top();
        auto q_t = st_q.top();        
        while (p_t->val == q_t->val) {  // breaks after reaching lowest common ancestor in stack
            lca = p_t;
            
            st_p.pop();
            st_q.pop();
            
            if (st_p.empty() || st_q.empty())   
                break;
            
            p_t = st_p.top();
            q_t = st_q.top(); 
        }
        
        return lca;
    }
};
