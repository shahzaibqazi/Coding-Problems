/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
# include <queue>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sumList = new ListNode();
        ListNode *curr = sumList;
        ListNode *ptr1 = l1, *ptr2 = l2;        
        
        int c = 0;  // for carry in addition 
        while (ptr1 and ptr2) {
            int n = ptr1->val + ptr2->val + c;  // include carry
            ListNode *node = new ListNode(n % 10);  
            
            curr->next = node;  // append node
            curr = curr->next;
            
            c = n/10;  // compute next carry
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } 
                
        if (ptr1 or ptr2) {  // any of the lists are still remaining
            ListNode *rem = ptr1 ? ptr1 : ptr2;  // assign the remaining list to rem
            curr->next = rem;  // append remaining nodes
           
            while (c and rem) {    // stop if no carry or list ends
                int n = rem->val + c;
                rem->val = n % 10;
                rem = rem->next;
                curr = curr->next;
                c = n/10;                
            }
        }
        
        if (c) {  // lists end but a carry remains
            curr->next = new ListNode(c);
        }
        
        return sumList->next;
    }
};
