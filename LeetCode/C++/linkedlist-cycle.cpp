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
    bool hasCycle(ListNode *head) {
        
        if (head != NULL and head->next != NULL) {
            ListNode* fptr = head;
            ListNode* sptr = head;

            while (fptr != NULL and fptr->next != NULL) {
                fptr = fptr->next->next;
                sptr = sptr->next;

                if (fptr == sptr){
                    return true;
                }
            }      
        }
        
        return false;            
    }
};
