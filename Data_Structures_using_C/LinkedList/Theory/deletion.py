class Node:
    def __init__(self, data):
        self.data=data
        self.next=None

def deleteAtBeginning(head):
    if head == None:
        print('List is empty')
        return head
    temp = head
    head = head.next
    del temp
    return head

def deleAtEnd(head):
    if head == None:
        print('List is empty')
        return head
    if head.next == None:
        del head
        head = None
        return head
    curr = head
    while curr.next.next != None:
        curr = curr.next
    temp=curr.next
    curr.next=None
    del temp
    return head 

def deleteAtPosition(head, position):
    if head == None:
        print('KList is empty')
        return head
    if position == 1:
        temp = head 
        head = head.next
        del temp
        return head
    curr = head
    for i in range(position - 2):
        if curr.next == None:
            print('Invalid position')
            return head
        curr = curr.next
    if curr.next == None:
        print('Invalid position')
        return head
    temp=curr.next
    curr.next=curr.next.next
    del temp
    return head

def displayList(head):
    while head != None:
        print(head.data, end=' ')
        head= head.next
    print()

head= None
head = Node(5)
head.next=Node(10)
head.next.next=Node(15)
head.next.next.next=Node(20)

head=deleteAtBeginning(head)
displayList(head)

head=deleAtEnd(head)
displayList(head)

head=deleteAtPosition(head, 2)
displayList(head)