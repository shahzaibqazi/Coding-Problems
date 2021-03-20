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
#include <queue>

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head) {
            ListNode *ptr = head;
            std::queue<ListNode*> evenNodes; 

            while (ptr->next) {
                evenNodes.push(ptr->next);
                ptr->next = ptr->next->next;
                if (ptr->next)
                    ptr = ptr->next;
            }

            while (!evenNodes.empty()) {
                ptr->next = evenNodes.front();
                evenNodes.pop();
                ptr = ptr->next;
            }
            ptr->next = NULL;            
        }
        return head;
    } 
};
