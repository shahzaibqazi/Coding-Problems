# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        tree = list()
        tree = self.postorderTraversalUtil(root, tree)
        return tree
    
    
    def postorderTraversalUtil(self, root: TreeNode, tree: List[int]) -> List[int]:
        if root:
            tree = self.postorderTraversalUtil(root.left, tree)
            tree = self.postorderTraversalUtil(root.right, tree)
            tree.append(root.val)
            
        return tree
