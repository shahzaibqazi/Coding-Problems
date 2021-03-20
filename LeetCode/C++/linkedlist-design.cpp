class Node {
public:
    int val;
    Node* next;
    
    Node(int v) {
        val = v;
        next = NULL;
    }
};

class MyLinkedList {
private:    
    Node* head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(head != NULL){
            Node* cur = head;
            
            int idx = 0;
            while(idx++ < index) {
                if (cur->next == NULL){
                    return -1;
                }
                else{
                    cur = cur->next;
                }
            }
            
            return cur->val;
        }
        else {
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* cur = new Node(val);
        cur->next = head;
        head = cur;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        
        if (head != NULL){
            Node* cur = head;
            while(cur->next != NULL){
                cur = cur->next;
            }                
            cur->next = node;
        }
        else {
            head = node;
        }
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node* node = new Node(val);
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        
        if(head != NULL){
            Node* cur = head;
            
            for (int i = 0; i < index-1; i++){
                if (cur->next != NULL){
                    cur = cur->next;
                }
            }
            node->next = cur->next;
            cur->next = node;

            return;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (head != NULL) {
            if (index == 0) {
                head = head->next;
                return;
            }
            if (head->next != NULL){
                Node* cur = head;
                int i;
                for (i=0; i < index-1; i++){
                    cur = cur->next;
                    if(cur->next == NULL){
                        return;
                    }
                }
                cur->next = cur->next->next;
                return;
            }
        }
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */