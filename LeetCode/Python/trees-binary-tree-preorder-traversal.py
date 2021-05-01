# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        tree = list()
        tree = self.preorderTraversalUtil(root, tree)
        return tree
    
    
    def preorderTraversalUtil(self, root: TreeNode, tree: List[int]) -> List[int]:
        if root:
            tree.append(root.val)
            tree = self.preorderTraversalUtil(root.left, tree)
            tree = self.preorderTraversalUtil(root.right, tree)
            
        return tree
