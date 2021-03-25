
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode(0, l1);
        ListNode *ptr_lo = temp, *ptr_hi = l1;
        ListNode *cur = l2, *ptr_2 = l2;
        
        while (ptr_hi && ptr_2) {
            if (ptr_hi->val >= ptr_2->val) {
                ptr_2 = ptr_2->next;
                ptr_lo->next = cur;
                cur->next = ptr_hi;
                ptr_lo = ptr_lo->next;
                cur = ptr_2;                
            }
            else {
                ptr_hi = ptr_hi->next;
                ptr_lo = ptr_lo->next;
            }
        }
        if (ptr_2) {
            ptr_lo->next = ptr_2;
        }
        return temp->next;
    }
};