/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getListLength(ListNode *head) {
        int len = 0;
        ListNode *ptr = head;
        
        while (ptr) {
            len++;
            ptr = ptr->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA and headB) {
            int lenA = getListLength(headA), lenB = getListLength(headB);  // get lengths of both Linked Lists

            ListNode *ptr_long = lenA >= lenB ? headA : headB;   // longer list
            ListNode *ptr_short = lenA < lenB ? headA : headB;  // shorter list

            for (int i=0; ptr_long and ptr_short; i++) {
                if (ptr_long == ptr_short) 
                    return ptr_long;  // or, return ptr_short
                ptr_short = i >= abs(lenA-lenB) ? ptr_short->next : ptr_short;  // for same starting point
                ptr_long = ptr_long->next;            
            }
        }
        return NULL;    // atleast one of the heads is null
    }
};