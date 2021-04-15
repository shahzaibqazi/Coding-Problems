class Node {
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int v): val(v), next(NULL), prev(NULL) {}
    Node(int v, Node* n, Node* p): val(v), next(n), prev(p) {}
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
        if(head){
            Node* cur = head;
            
            int idx = 0;
            while(idx++ < index) {
                if (!cur->next){
                    return -1;
                }
                else{
                    cur = cur->next;
                }
            }
            return cur->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* cur = new Node(val, head, NULL);
        if(head){
            head->prev = cur;
        }    
        head = cur;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        // Node* node = new Node(val);
        
        if (head){
            Node* cur = head;
            while(cur->next){
                cur = cur->next;
            }                
            cur->next = new Node(val, NULL, cur);
        }
        else {
            head = new Node(val);
        }
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node* temp = new Node(0, head, NULL);  // added before head for ease in algorithm
        Node* cur = temp;
        
        int i = -1;
        while (i++ < index-1) {  // loop until reach index or end of list
            if (!cur->next)
                break;
            cur = cur->next;
        }
        
        if (i == index) {  // index is valid
            Node* node = new Node(val, cur->next, cur);  // node to be inserted
            if (index == 0) {  // new head node inserted (index=0)
                head = node;
            }
            if (cur->next){  // 'cur' is not the last node in list
                cur->next->prev = node;
            }
            cur->next = node;
        }
        
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* temp = new Node(0, head, NULL);   // added before head for ease in algorithm
        Node* cur = temp;
        
        int i = -1;
        while (i++ < index-1) {  // loop until reach index or end of list
            if (!cur->next)
                break;
            cur = cur->next;
        }
        
        if (i == index) {   // index is valid
            if (index == 0){  // head node to be deleted (index=0)
                head = cur->next->next;
            }
            if (cur->next) {    // 'cur' is not the last node in list
                cur->next = cur->next->next;
            }
            if (cur->next) {    // 'cur' is still not last node in list
                cur->next->prev = cur; 
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
