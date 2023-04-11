class Node:
    def __init__(self, data):
        self.data = data
        self.next=None
        self.prev=None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insertAtBeginning(self, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next=new_node
            new_node.prev=current

    def insertAtEnd(self, new_data):
        new_node=Node(new_data)
        if self.head is None:
            self.head=new_node
        else:
            current=self.head
            while current.next is not None:
                current = current.next
            current.next=new_node
            new_node.prev=current

    def insertAfter(self, prev_node_data, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current is not None:
                if current.data == prev_node_data:
                    if current.next is None:
                        current.next = new_node
                        new_node.prev=current
                    else:
                        new_node.next=current.next
                        current.next.prev=new_node
                        current.next=new_node
                        new_node.prev=current
                    break
                current=current.next
    
    def deleteNode(self, del_node_data):
        if self.head is None:
            return
        current = self.head
        while current is not None:
            if current.data == del_node_data:
                if current.prev is None:
                    self.head=current.next
                    self.head.prev=None
                elif current.next is None:
                    current.prev.next=None
                else:
                    current.prev.next=current.next
                    current.next.prev=current.prev
                break
            current =current.next

    def printList(self):
        if self.head is None:
            print('Doubly linked is empty')
        else:
            current=self.head
            while current is not None:
                print(current.data, end=' ')
                current=current.next
            print()

doublyLinkedList = DoublyLinkedList()

# Insert nodes at the beginning, end, and after a node
doublyLinkedList.insertAtBeginning(5)
doublyLinkedList.insertAtBeginning(10)
doublyLinkedList.insertAtEnd(20)
doublyLinkedList.insertAtEnd(30)
doublyLinkedList.insertAfter(10, 15)
doublyLinkedList.insertAfter(30, 25)

# Print the doubly linked list
doublyLinkedList.printList()

# Delete nodes from the doubly linked list
doublyLinkedList.deleteNode(5)
doublyLinkedList.deleteNode(15)
doublyLinkedList.deleteNode(30)

# Print the doubly linked list again
doublyLinkedList.printList()    
