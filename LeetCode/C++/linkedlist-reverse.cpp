
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = new ListNode(0, head);
        ListNode* prev = temp, *curr = temp->next;
        ListNode* end = NULL, *next;

        while(curr != end) {
            next = curr->next;
            while(next != end) {
                prev->next = next;
                curr->next = next->next;
                next->next = curr;
                next = curr->next;
                prev = prev->next;
            }
            end = curr;
            prev = temp;
            curr = temp->next;
        }
        return temp->next;
    }
};