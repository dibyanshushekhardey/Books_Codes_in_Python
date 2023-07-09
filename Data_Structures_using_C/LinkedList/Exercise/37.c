#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
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

// Function to create a header linked list
struct Node* createHeaderLinkedList() {
    // Create a header node with data -1
    struct Node* headerNode = createNode(-1);
    return headerNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node* header, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = header->next;
    header->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* header) {
    struct Node* temp = header->next;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a header linked list
    struct Node* header = createHeaderLinkedList();

    // Insert nodes at the beginning of the linked list
    insertAtBeginning(header, 10);
    insertAtBeginning(header, 20);
    insertAtBeginning(header, 30);
    insertAtBeginning(header, 40);
    insertAtBeginning(header, 50);

    // Display the linked list
    displayList(header);

    return 0;
}
