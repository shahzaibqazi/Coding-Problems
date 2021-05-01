# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        return self.hasPathSumRecursive(root, targetSum, 0) if root else False
        
        
    def hasPathSumRecursive(self, root: TreeNode, targetSum: int, pathSum: int) -> bool:
        pathSum += root.val
        
        if not root.left and not root.right:  # leaf node case
            return True if pathSum == targetSum else False
        
        hasPathSum_l = hasPathSum_r = False
        sum_local = pathSum
        
        hasPathSum_l = self.hasPathSumRecursive(root.left, targetSum, pathSum) if root.left \
                        else False
        pathSum = sum_local  # resetting total path sum value to the local sum of node
        
        hasPathSum_r = self.hasPathSumRecursive(root.right, targetSum, pathSum) if root.right \
                        else False
        pathSum = sum_local
        
        return hasPathSum_l or hasPathSum_r
