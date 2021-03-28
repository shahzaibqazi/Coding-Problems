/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead = NULL;
        
        if (head) {
            Node *ptr1 = head, *ptr2 = head->next;

            while (ptr1) {  // add new nodes in list as: A-->A'-->B-->B'-->...
                Node *node = new Node(ptr1->val);
                node->next = ptr2;
                ptr1->next = node;

                ptr1 = ptr2;
                ptr2 = ptr2 ? ptr2->next : NULL;
            }

            ptr1 = head;
            ptr2 = head->next;
            
            while (ptr2) {  // setting 'random' of new nodes
                ptr2->random = ptr1->random ? ptr1->random->next : NULL;
                
                ptr1 = ptr2->next;
                ptr2 = ptr1 ? ptr1->next : NULL;
            }

            ptr1 = head;
            ptr2 = head->next;
            newHead = ptr2;    // head set to first node of the new list

            while (ptr2->next) {    // setting 'next' of new and original nodes
                ptr1->next = ptr2->next;
                ptr2->next = ptr2->next->next;
                
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            ptr1->next = NULL;
        }
        
        return newHead;
    }
};