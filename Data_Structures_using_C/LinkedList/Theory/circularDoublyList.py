class Node:
    def __init__(self, data):
        self.data=data
        self.prev=None
        self.next=None

class CircularDoublyLinkedList:
    def __init__(self):
        self.head=None
    
    def insertAtBeginning(self, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head=new_node
            new_node.next=new_node
            new_node.prev=new_node
        else:
            last_node=self.head.prev
            last_node.next=new_node
            new_node.prev=last_node
            new_node.next=self.head
            self.head.prev=new_node
            self.head=new_node
    
    def insertAtEnd(self, new_data):
        new_node=Node(new_data)
        if self.head is None:
            self.head = new_node
            new_node.next=new_node
            new_node.prev=new_node
        else:
            last_node=self.head.prev
            last_node.next=new_node
            new_node.prev=last_node
            new_node.next=self.head
            self.head.prev=new_node

    def deleteFromBeginning(self):
        if self.head is None:
            return
        elif self.head.next == self.head:
            self.head=None
        else:
            last_node=self.head.prev
            second_node=self.head.next
            second_node.prev=last_node
            last_node.next=second_node
            self.head=second_node
    
    def deleteFromEnd(self):
        if self.head is None:
            return
        elif self.head.next == self.head:
            self.head = None
        else:
            last_node=self.head.prev.prev
            last_node.next=self.head
            self.head.prev=last_node
    
    def printList(self):
        if self.head is None:
            print('Circular Doubly Linked List is empty')
        else:
            current=self.head
            while True:
                print(current.data, end=' ')
                current=current.next
                if current == self.head:
                    break
            print()

circularDoublyLinkedList = CircularDoublyLinkedList()

# Insert nodes at the beginning and end of the list
circularDoublyLinkedList.insertAtBeginning(5)
circularDoublyLinkedList.insertAtBeginning(10)
circularDoublyLinkedList.insertAtEnd(20)
circularDoublyLinkedList.insertAtEnd(30)

# Print the circular doubly linked list
circularDoublyLinkedList.printList()

# Delete nodes from the beginning and end of the list
circularDoublyLinkedList.deleteFromBeginning()
circularDoublyLinkedList.deleteFromEnd()

# Print the circular doubly linked list again
circularDoublyLinkedList.printList()
