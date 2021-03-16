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
    ListNode *cycleFptr(ListNode *head) {  // if cycle found, returns the fast pointer 
        
        if (head != NULL and head->next != NULL) {
            ListNode* fptr = head;
            ListNode* sptr = head;

            while (fptr != NULL and fptr->next != NULL) {
                fptr = fptr->next->next;
                sptr = sptr->next;

                if (fptr == sptr){
                    return fptr;
                }
            }      
        }
        return NULL;  // no cycle found           
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* fptr = cycleFptr(head);
        if (fptr){
            ListNode* sptr = head;
            
            while (fptr != sptr) {
                fptr = fptr->next;
                sptr = sptr->next;
            }
        }            
        return fptr;
    }
};
