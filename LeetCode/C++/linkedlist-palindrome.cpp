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
#include <stack>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *ptr = head;
        std::stack <int> nodeVals;
        
        while (ptr) {
            nodeVals.push(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head;
        
        while (!nodeVals.empty()) {
            if (nodeVals.top() != ptr->val) {
                return false;
            }
            nodeVals.pop();
            ptr = ptr->next;
        }
        return true;        
    }
};
