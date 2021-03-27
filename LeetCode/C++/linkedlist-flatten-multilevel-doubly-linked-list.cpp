
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* connectLists(Node* l1, Node* l2) {
        if (!l1) {
            return l2;  // if l2==NULL, return NULL
        }
        
        Node *temp = new Node();
        temp->next = l1;
        
        if (l2){  // no need to traverse if l2 is NULL
            Node *ptr = temp;
            while (ptr->next) {
                ptr = ptr->next;
            }
            ptr->next = l2;
            l2->prev = ptr;
        }
        
        return temp->next;
    }
    
    Node* flatten(Node* head) {
        Node *ptr = head;
        Node *newList = ptr;
        
        while (ptr) {
            ptr = ptr->next;  // next in the original list
            if (newList->child) {
                newList->next = flatten(newList->child);
                newList->next->prev = newList;
                newList = connectLists(newList, ptr);  // connect flattened part to next part of the list
                newList->child = NULL;  // remove the child
            }
            newList = ptr;  // next in original list, after flattening
        }
        
        return head;
    }
    
};