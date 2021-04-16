# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def cycleFptr(self, head: ListNode) -> ListNode:
        if head and head.next:
            fptr, sptr = head, head
            
            while fptr and fptr.next:
                fptr, sptr = fptr.next.next, sptr.next
                
                if fptr == sptr:
                    return fptr
        
        return None
        
        
    def detectCycle(self, head: ListNode) -> ListNode:
        fptr = self.cycleFptr(head)
        
        if fptr:
            sptr = head
            
            while fptr is not sptr:
                fptr, sptr = fptr.next, sptr.next
                
        return fptr
    
