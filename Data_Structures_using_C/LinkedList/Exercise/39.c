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

// Function to delete all nodes with negative values from the linked list
void deleteNodesWithNegativeValues(struct Node* header) {
    struct Node* current = header->next;
    struct Node* prev = header;

    while (current != NULL) {
        if (current->data < 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
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
    insertAtBeginning(header, -5);
    insertAtBeginning(header, 20);
    insertAtBeginning(header, -15);
    insertAtBeginning(header, 30);
    insertAtBeginning(header, -25);

    // Display the original linked list
    printf("Original Linked List:\n");
    displayList(header);

    // Delete nodes with negative values from the linked list
    deleteNodesWithNegativeValues(header);

    // Display the modified linked list
    printf("\nAfter Deleting Nodes with Negative Values:\n");
    displayList(header);

    return 0;
}
