class Node:
    def __init__(self, data):
        self.data=data
        self.next=None

def sortList(head):
    if head == None:
        print('List is empty')
        return head
    curr = head
    while curr != None:
        temp = curr.next
        while temp != None:
            if curr.data > temp.data:
                curr.data, temp.data = temp.data, curr.data
            temp = temp.next
        curr = curr.next
    return head

def deleteList(head):
    curr = head
    while curr != None:
        prev = curr
        curr = curr.next
        del prev
    head = None
    return head

def displayList(head):
    while head != None:
        print(head.data, end=' ')
        head = head.next

    print()

head = None

# insert values into the list
head = Node(5)
head.next=Node(10)
head.next.next=Node(3)
head.next.next.next=Node(20)

head = sortList(head)
displayList(head)

head = deleteList(head)
displayList(head)