#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the singly linked list
void insertAtBeginning(struct Node** head, struct Node* newNode) {
    newNode->next = *head;
    *head = newNode;
}

// Function to find the nth element from the end of the singly linked list
void printNthFromEnd(struct Node* head, int n) {
    if (head == NULL || n <= 0) {
        printf("Invalid value of n.\n");
        return;
    }

    struct Node* fastPtr = head;
    struct Node* slowPtr = head;

    // Move the fast pointer n positions ahead
    for (int i = 0; i < n; i++) {
        if (fastPtr == NULL) {
            printf("The linked list does not have %d elements.\n", n);
            return;
        }
        fastPtr = fastPtr->next;
    }

    // Move both the pointers until the fast pointer reaches the end
    while (fastPtr != NULL) {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }

    // The slow pointer is now at the nth element from the end
    printf("The %dth element from the end is: %d\n", n, slowPtr->data);
}

// Function to display the singly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create nodes and insert them at the beginning of the singly linked list
    insertAtBeginning(&head, createNode(10));
    insertAtBeginning(&head, createNode(20));
    insertAtBeginning(&head, createNode(30));
    insertAtBeginning(&head, createNode(40));
    insertAtBeginning(&head, createNode(50));

    // Display the singly linked list
    printf("Original Singly Linked List:\n");
    displayList(head);

    // Find and print the nth element from the end of the singly linked list
    int n;
    printf("\nEnter the value of n: ");
    scanf("%d", &n);
    printNthFromEnd(head, n);

    return 0;
}
