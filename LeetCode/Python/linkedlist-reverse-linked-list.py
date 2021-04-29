# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        temp = ListNode(0, head)
        prev, curr, end = temp, temp.next, None
        
        while curr is not end:
            next_ = curr.next
            
            while next_ is not end:
                prev.next, curr.next = next_, next_.next
                next_.next = curr
                next_, prev = curr.next, prev.next
            
            end, prev = curr, temp
            curr = temp.next
            
        return temp.next
