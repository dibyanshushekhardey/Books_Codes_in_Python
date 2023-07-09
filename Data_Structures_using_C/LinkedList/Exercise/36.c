#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular doubly linked list
void insertAtBeginning(struct Node** head, struct Node* newNode) {
    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        // Insert the new node at the beginning
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to interchange the kth and (k+1)th node of the circular doubly linked list
void interchangeNodes(struct Node** head, int k) {
    if (*head == NULL || k <= 0) {
        printf("Invalid value of k.\n");
        return;
    }

    struct Node* current = *head;
    int count = 1;

    // Find the kth node
    while (count < k && current->next != *head) {
        current = current->next;
        count++;
    }

    if (count < k) {
        printf("The circular doubly linked list does not have %d nodes.\n", k);
        return;
    }

    // Store the kth and (k+1)th nodes in separate variables
    struct Node* kthNode = current;
    struct Node* nextNode = current->next;

    // Interchange the links
    kthNode->prev->next = nextNode;
    nextNode->prev = kthNode->prev;
    kthNode->next = nextNode->next;
    nextNode->next->prev = kthNode;
    nextNode->next = kthNode;
    kthNode->prev = nextNode;
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Circular Doubly Linked List: ");
    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create nodes and insert them at the beginning of the circular doubly linked list
    insertAtBeginning(&head, createNode(10));
    insertAtBeginning(&head, createNode(20));
    insertAtBeginning(&head, createNode(30));
    insertAtBeginning(&head, createNode(40));
    insertAtBeginning(&head, createNode(50));

    // Display the original circular doubly linked list
    printf("Original Circular Doubly Linked List:\n");
    displayList(head);

    int k;
    printf("\nEnter the value of k: ");
    scanf("%d", &k);

    // Interchange the kth and (k+1)th node of the circular doubly linked list
    interchangeNodes(&head, k);

    // Display the modified circular doubly linked list
    printf("\nAfter Interchanging Nodes:\n");
    displayList(head);

    return 0;
}
