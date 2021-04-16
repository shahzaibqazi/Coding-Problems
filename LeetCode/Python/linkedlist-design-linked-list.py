class Node:
    
    def __init__(self, _val=None, _next=None):
        self.val = _val
        self.next = _next
        
        
class MyLinkedList:

    def __init__(self, head=None):
        """
        Initialize your data structure here.
        """
        self.head = head
    

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        node = self.head
        list_len = self.listLength()
        
        for i in range(list_len):
            if i == index:
                return node.val
            node = node.next
        
        return -1
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        newNode = Node(val,self.head)
        self.head = newNode
        return
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        node = self.head
        newNode = Node(val)
        if self.head is not None:
            while node.next is not None:
                node = node.next

            node.next = newNode
        else:
            self.head = newNode
            
        return
        

    def listLength(self) -> int:
        node = self.head
        list_len = 0
        
        while node is not None:
            list_len += 1
            node = node.next
        
        return list_len
        
        
    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index == 0:
            self.head = Node(val, self.head)
            return
        
        list_len = self.listLength()
        if index <= list_len:
            node = self.head
            newNode = Node(val)
            if index == list_len:
                while node.next is not None:
                    node = node.next
                node.next = newNode

            if index < list_len:
                for i in range(index-1):
                    node = node.next
                newNode.next = node.next
                node.next = newNode
        return            

            
    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index == 0:
            if self.head is not None:
                self.head = self.head.next
            return

        list_len = self.listLength()
        if index < list_len:
            node = self.head
            for i in range(index-1):
                node = node.next
            node.next = node.next.next
                
        return
            

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
