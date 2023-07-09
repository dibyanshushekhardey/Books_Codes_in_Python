#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular header linked list
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

// Function to create a circular header linked list
struct Node* createCircularHeaderLinkedList() {
    // Create a header node with data -1
    struct Node* headerNode = createNode(-1);
    headerNode->next = headerNode;
    return headerNode;
}

// Function to insert a node at the beginning of the circular header linked list
void insertAtBeginning(struct Node* header, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = header->next;
    header->next = newNode;
}

// Function to delete a node from the circular header linked list
void deleteNode(struct Node* header, int key) {
    if (header == NULL || header->next == header) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = header->next;
    struct Node* prev = header;

    // Search for the key in the list
    while (current != header) {
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            printf("Node with data %d is deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Node with data %d not found.\n", key);
}

// Function to display the circular header linked list
void displayList(struct Node* header) {
    struct Node* temp = header->next;

    if (temp == NULL || temp == header) {
        printf("The list is empty.\n");
        return;
    }

    printf("Circular Header Linked List: ");
    while (temp != header) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a circular header linked list
    struct Node* header = createCircularHeaderLinkedList();

    // Insert nodes at the beginning of the circular header linked list
    insertAtBeginning(header, 10);
    insertAtBeginning(header, 20);
    insertAtBeginning(header, 30);
    insertAtBeginning(header, 40);
    insertAtBeginning(header, 50);

    // Display the circular header linked list
    displayList(header);

    // Delete a node from the circular header linked list
    int key;
    printf("\nEnter the value of the node to delete: ");
    scanf("%d", &key);
    deleteNode(header, key);

    // Display the modified circular header linked list
    displayList(header);

    return 0;
}
