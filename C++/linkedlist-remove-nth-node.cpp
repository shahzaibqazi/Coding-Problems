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
    /** Returns number of nodes in the linked list*/
    int getListLength(ListNode *head) {
        int len = 0;
        ListNode *ptr = head;
        
        while (ptr) {
            len++;
            ptr = ptr->next;
        }
        return len;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid, and returns head*/
    ListNode* deleteAtIndex(ListNode *head, int index) {
        if (head) {            
            if (index == 0) {
                head = head->next;
                return head;
            }
            if (head->next){
                ListNode *cur = head;
                int i;
                for (i=0; i < index-1; i++){
                    cur = cur->next;
                    if(!cur->next){
                        return head;
                    }
                }
                cur->next = cur->next->next;
                return head;
            }
        }
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head) {
            head = deleteAtIndex(head, getListLength(head)-n);
        }
        return head;
    }
};
