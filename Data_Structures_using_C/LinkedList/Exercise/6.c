#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
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

// Function to insert a node at the end of the circular linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        (*head)->next = *head;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Function to copy a circular linked list
struct Node* copyCircularList(struct Node* original) {
    if (original == NULL) {
        return NULL;
    }

    // Create the head node of the new list
    struct Node* newHead = createNode(original->data);

    // Initialize pointers for traversal
    struct Node* originalCurr = original->next;
    struct Node* newCurr = newHead;

    // Copy the remaining nodes
    while (originalCurr != original) {
        struct Node* newNode = createNode(originalCurr->data);
        newCurr->next = newNode;
        newCurr = newNode;
        originalCurr = originalCurr->next;
    }

    // Connect the last node to the new head to form a circular list
    newCurr->next = newHead;

    return newHead;
}

int main() {
    struct Node* originalList = NULL;
    struct Node* copiedList = NULL;

    // Insert nodes into the original circular linked list
    insertNode(&originalList, 1);
    insertNode(&originalList, 2);
    insertNode(&originalList, 3);
    insertNode(&originalList, 4);
    insertNode(&originalList, 5);

    // Display the original list
    printf("Original List: ");
    displayList(originalList);

    // Copy the original list
    copiedList = copyCircularList(originalList);

    // Display the copied list
    printf("Copied List: ");
    displayList(copiedList);

    return 0;
}
