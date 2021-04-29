# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        temp = ListNode(0, head)
        node = temp
        
        while node.next:
            if node.next.val is val:
                node.next = node.next.next
            else:
                node = node.next
                
        return temp.next
