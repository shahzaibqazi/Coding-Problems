# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ## Checks if two trees are identical
    def isSymmetric(self, root: TreeNode) -> bool:
        if root:
            return self.areSymmetricIdentical(root.left, root.right)
        
        
    ## Checks if two trees are symmetric identical
    def areSymmetricIdentical(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2:
            return True
        
        if root1 and root2:
            return root1.val == root2.val \
                and self.areSymmetricIdentical(root1.left, root2.right) \
                and self.areSymmetricIdentical(root1.right, root2.left);
        
        return False
