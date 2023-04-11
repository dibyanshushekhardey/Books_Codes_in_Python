class Node:
    def __init__(self, data):
        self.data=data
        self.next=None

class HeaderLinkedList:
    def __init__(self):
        self.head=Node(None)
    def insert(self, new_data):
        new_node=Node(new_data)
        new_node.next=self.head.next
        self.head.next=new_node

    def delete(self, target_data):
        current=self.head.next
        previous=self.head
        while current is not None:
            if current.data == target_data:
                previous.next = current.next
                current.next=None
                return
            else:
                previous=current
                current=current.next

    def printList(self):
        current=self.head.next
        while current is not None:
            print(current.data, end=' ')
            current=current.next
        print()

headerLinkedList = HeaderLinkedList()

# Insert nodes into the list
headerLinkedList.insert(10)
headerLinkedList.insert(20)
headerLinkedList.insert(30)
headerLinkedList.insert(40)

# Print the list
headerLinkedList.printList()

# Delete a node from the list
headerLinkedList.delete(20)

# Print the list again
headerLinkedList.printList()

