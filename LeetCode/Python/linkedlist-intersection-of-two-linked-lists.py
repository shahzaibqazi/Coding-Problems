# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getListLength(self, head: ListNode) -> int:
        listLen = 0
        node = head
        while node: listLen += 1; node = node.next
            
        return listLen
    
        
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA and headB:
            lenA, lenB = self.getListLength(headA), self.getListLength(headB)
            
            longList = headA if lenA >= lenB else headB  # longer list
            shortList = headA if lenA < lenB else headB  # shorter list
            
            for i in range(abs(lenA-lenB)): longList = longList.next  # for same starting point
            
            while longList and shortList:
                if longList == shortList: return longList     # or, return shortList
                shortList, longList = shortList.next, longList.next
                
            return None
