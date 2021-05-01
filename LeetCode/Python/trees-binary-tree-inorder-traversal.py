# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        tree = list()
        tree = self.inorderTraversalUtil(root, tree)
        return tree
    
    
    def inorderTraversalUtil(self, root: TreeNode, tree: List[int]) -> List[int]:
        if root:
            tree = self.inorderTraversalUtil(root.left, tree)
            tree.append(root.val)
            tree = self.inorderTraversalUtil(root.right, tree)
            
        return tree
