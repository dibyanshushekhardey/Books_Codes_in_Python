class Node:
    def __init__(self, coefficient, exponent):
        self.coefficient=coefficient
        self.exponent=exponent
        self.next=None

class Polynomial:
    def __init__(self):
        self.head=None
    def insert(self, coefficient, exponent):
        new_node=Node(coefficient, exponent)
        if self.head is None:
            self.head=new_node
        else:
            current=self.head
            previous=None
            while current is not None and current.exponent > exponent:
                previous=current
                current=current.next
            if current is None:
                previous.next = new_node
            elif current.exponent == exponent:
                current.coefficient += coefficient
                if current.coefficient == 0:
                    self.delete(exponent)
            elif current.exponent < exponent:
                new_node.next=current
                if previous is None:
                    self.head=new_node
                else:
                    previous.next=new_node
    
    def delete(self, exponent):
        current=self.head
        previous=None
        while current is not None and current.exponent != exponent:
            previous=current
            current=current.next
        if current is None:
            return
        if previous is None:
            self.head=current.next
        else:
            previous.next=current.next
    
    def add(self, other):
        result=Polynomial()
        current =self.head
        other_current=other.head
        while current is not None and other_current is not None:
            if current.exponent == other_current.exponent:
                result.insert(current.coefficient + other_current.coefficient, current.exponent)
                current = current.next
                other_current = other_current.next
            elif current.exponent > other_current.exponent:
                result.insert(current.coefficient, current.exponent)
                current = current.next
            else:
                result.insert(other_current.coefficient, other_current.exponent)
                other_current = other_current.next
        while current is not None:
            result.insert(current.coefficient, current.exponent)
            current = current.next
        while other_current is not None:
            result.insert(other_current.coefficient, other_current.exponent)
            other_current = other_current.next
        return result
    
    def subtract(self, other):
        result = Polynomial()
        current = self.head
        other_current = other.head
        while current is not None and other_current is not None:
            if current.exponent == other_current.exponent:
                result.insert(current.coefficient - other_current.coefficient, current.exponent)
                current = current.next
                other_current = other_current.next
            elif current.exponent > other_current.exponent:
                result.insert(current.coefficient, current.exponent)
                current = current.next
            else:
                result.insert(-other_current.coefficient, other_current.exponent)
                other_current = other_current.next
        while current is not None:
            result.insert(current.coefficient, current.exponent)
            current = current.next
        while other_current is not None:
            result.insert(-other_current.coefficient, other_current.exponent)
            other_current = other_current.next
        return result

    def printPolynomial(self):
        current = self.head
        while current is not None:
            if current.coefficient > 0:
                print("+" + str(current.coefficient), end="")
            else:
                print(str(current.coefficient), end="")
            if current.exponent > 1:
                print("x^" + str(current.exponent), end="")
            elif current.exponent == 1:
                print("x", end="")
            current = current.next

# create two polynomials
poly1 = Polynomial()
poly1.insert(3, 4)
poly1.insert(5, 3)
poly1.insert(2, 2)
poly1.insert(4, 1)

poly2 = Polynomial()
poly2.insert(1, 5)
poly2.insert(2, 4)
poly2.insert(3, 2)
poly2.insert(1, 1)
poly2.insert(2, 0)

# print the two polynomials
print("Polynomial 1: ", end="")
poly1.printPolynomial()

print("\nPolynomial 2: ", end="")
poly2.printPolynomial()

# add the two polynomials
result = poly1.add(poly2)
print("\n\nResult of addition: ", end="")
result.printPolynomial()

# subtract the two polynomials
result = poly1.subtract(poly2)
print("\nResult of subtraction: ", end="")
result.printPolynomial()
