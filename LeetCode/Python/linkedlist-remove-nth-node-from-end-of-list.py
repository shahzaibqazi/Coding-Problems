# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        temp = ListNode(0, head)
        node1, node2 = temp, temp
        
        for i in range(n):
            node1 = node1.next
            
        while node1.next:
            node1, node2 = node1.next, node2.next
        
        node2.next = node2.next.next
        
        return temp.next
