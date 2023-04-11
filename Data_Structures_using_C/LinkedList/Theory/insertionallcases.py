class Node:
    def __init__(self, data):
        self.data=data
        self.next=None
def insertAtBeginning(head, data):
    newNode=Node(data)
    newNode.next=head
    head = newNode
    return head

def insertAtEnd(head, data):
    newNode=Node(data)
    if head == None:
        head = newNode
        return head
    curr=head
    while curr.next != None:
        curr = curr.next
    curr.next=newNode
    return head

def insertAtPosition(head, data, position):
    newNode = Node(data)
    if position == 1:
        newNode.next = head
        head = newNode
        return head
    curr = head
    for i in range(position-2):
        if curr == None:
            print('Invalid position')
            return head
        curr = curr.next
    if curr == None:
        print('invalid position')
        return head
    newNode.next=curr.next
    curr.next=newNode
    return head

def displayList(head):
    while head != None:
        print(head.data, end=' ')
        head=head.next
    print()

head = None

# insert at beginning
head = insertAtBeginning(head, 5)
head = insertAtBeginning(head, 10)
displayList(head)

# insert at end
head = insertAtEnd(head, 15)
head = insertAtEnd(head, 20)
displayList(head)

# insert at position
head = insertAtPosition(head, 25, 3)
head = insertAtPosition(head, 30, 6) 
displayList(head)   
