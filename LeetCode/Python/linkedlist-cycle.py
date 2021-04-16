# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is not None and head.next is not None:
            fptr = head
            sptr = head
            
            while fptr and fptr.next:
                fptr = fptr.next.next
                sptr = sptr.next
                
                if fptr == sptr:
                    return True
                
            return False
