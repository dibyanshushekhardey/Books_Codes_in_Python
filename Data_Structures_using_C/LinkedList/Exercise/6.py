class Node:
    def __init__(self, data=None):
        self.data=data
        self.next=None

class CircularLinkedList:
    def __init__(self):
        self.head = None
    def insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head=new_node
            new_node.next=self.head
        else:
            current=self.head
            while current.next != self.head:
                current=current.next
            current.next=new_node
            new_node.next=self.head

    def print_list(self):
        if self.head is None:
            print('List is empty')
            return 
        current=self.head
        while True:
            print(current.data)
            current=current.next
            if current == self.head:
                break

def copy_circular_linked_list(original_list):
    if original_list.head is None:
        return None
    new_list=CircularLinkedList()
    current=original_list.head
    while True:
        new_list.insert(current.data)
        current=current.next
        if current == original_list.head:
            break
    return new_list

original_list = CircularLinkedList()
original_list.insert(1)
original_list.insert(2)
original_list.insert(3)
original_list.insert(4)
original_list.insert(5)

print("Original list:")
original_list.print_list()

new_list = copy_circular_linked_list(original_list)

print("New list:")
new_list.print_list()
