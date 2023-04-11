class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insertBegin(self, data):
        newNode = Node(data)
        if self.head == None:
            self.head = newNode
            newNode.next = self.head 
        else:
            curr = self.head
            while curr.next != self.head:
                curr = curr.next
            curr.next=newNode
            newNode.next=self.head
            self.head=newNode
    
    def insertend(self,data):
        newNode=Node(data)
        if self.head == None:
            self.head = newNode
            newNode.next=self.head
        else:
            curr = self.head
            while curr.next != self.head:
                curr = curr.next
            curr.next=newNode
            newNode.next=self.head

    def deleteBegin(self):
        if self.head == None:
            print('List is empty')
            return
        elif self.head.next == self.head:
            del self.head
            self.head = None
        else:
            curr = self.head
            while curr.next != self.head:
                curr = curr.next
            curr.next=self.head.next
            del self.head
            self.head = curr.next
    
    def deleteEnd(self):
        if self.head == None:
            print('List is empty')
            return
        elif self.head.next == self.head:
            del self.head
            self.head = None
        else:
            curr = self.head
            while curr.next.next != self.head:
                curr = curr.next
            del curr.next
            curr.next = self.head
        
    def display(self):
        if self.head == None:
            print('List is empty')
            return
        curr = self.head
        while curr.next != self.head:
            print(curr.data, end=' ')
            curr = curr.next
        print(curr.data, end=' ')
        print()

clist = CircularLinkedList()

clist.insertend(5)
clist.insertend(10)
clist.insertend(15)
clist.insertBegin(0)
clist.insertBegin(-5)

clist.display()

clist.deleteBegin()
clist.deleteEnd()

clist.display()
