# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        tree = list()
        
        if root:
            q = list()
            q.append(root)
            
            while q:
                level = list()
                q_size = len(q)
                
                for i in range(q_size):
                    node = q.pop(0)
                    level.append(node.val)
                    
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                
                tree.append(level)
        
        return tree
