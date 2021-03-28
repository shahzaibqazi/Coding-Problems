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
    
    ListNode* rotateRight(ListNode* head, int k) {        
        ListNode *temp = new ListNode(0, head);

        if (head && head->next) {  // no rotation in case of single or no node
            ListNode *ptr1 = temp, *ptr2 = temp;
            int listLen = 0;

            while (ptr1->next) {
                ptr1 = ptr1->next;
                listLen++;
            }
            
            k %= listLen;  // to limit k within list length
            ptr1 = temp;
            
            for (int i=0; i < k; i++) {  // making k-nodes difference between ptr1 and ptr2
                ptr1 = ptr1->next;
            }
            
            while (ptr1->next) {  // traverse both ptrs until last node
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }  // loop ends with ptr2 pointing to the new last node
            
            ptr1->next = temp->next;
            temp->next = ptr2->next;
            ptr2->next = NULL;
        }
        return temp->next;
    }
};