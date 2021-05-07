# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        return self.buildTreeInPostorder(inorder, 0, len(inorder)-1,\
                                    postorder, 0, len(postorder)-1)
        
    def buildTreeInPostorder(self, inorder: List[int], in_start: int, in_end: int,\
                            postorder: List[int], post_start: int, post_end: int) -> TreeNode:
        if in_end < in_start or post_end < post_start:  # no node left
            return None
        
        # Last element in Postorder should be root
        rootVal = postorder[post_end]
        root = TreeNode(rootVal)
        
        if in_start is in_end or post_start is post_end:
            return root
        
        # Find root in Inorder
        root_idx = inorder.index(rootVal)
        n_left = root_idx - in_start;   # #nodes in left branch
        n_right = in_end - root_idx;  # #nodes in right branch
        
        root.left = self.buildTreeInPostorder(inorder, in_start, root_idx-1,\
                                       postorder, post_start, post_end-n_right-1)
        root.right = self.buildTreeInPostorder(inorder, root_idx+1, in_end, 
                                         postorder, post_start+n_left, post_end-1)
        
        return root
