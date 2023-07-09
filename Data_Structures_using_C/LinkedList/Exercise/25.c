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

// Function to insert a node at the end of the circular header linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        newNode->next = *head;
    } else {
        // Traverse to the last node
        struct Node* temp = (*head)->next;
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular header linked list
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

// Function to delete the first node from the circular header linked list
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    // If the list has only one node, delete it and set the head to NULL
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    // Find the last node in the list
    struct Node* lastNode = *head;
    while (lastNode->next != *head) {
        lastNode = lastNode->next;
    }

    // Move the head to the next node
    struct Node* nextNode = (*head)->next;
    free(*head);
    *head = nextNode;

    // Update the last node's next pointer
    lastNode->next = *head;
}

// Function to delete the last node from the circular header linked list
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    // If the list has only one node, delete it and set the head to NULL
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    // Find the second last node in the list
    struct Node* secondLastNode = *head;
    while (secondLastNode->next->next != *head) {
        secondLastNode = secondLastNode->next;
    }

    // Free the last node and update the second last node's next pointer
    struct Node* lastNode = secondLastNode->next;
    free(lastNode);
    secondLastNode->next = *head;
}

// Function to delete a specific node with the given value from the circular header linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        return;
    }

    // If the value is found at the head node, delete the first node
    if ((*head)->data == value) {
        deleteFirstNode(head);
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    // Traverse the list to find the node with the given value
    do {
        prev = current;
        current = current->next;
    } while (current != *head && current->data != value);

    // If the value is found, delete the node
    if (current->data == value) {
        prev->next = current->next;
        free(current);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular header linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Display the original circular header linked list
    printf("Original List: ");
    displayList(head);

    // Delete the first node from the circular header linked list
    deleteFirstNode(&head);
    printf("After deleting the first node: ");
    displayList(head);

    // Delete the last node from the circular header linked list
    deleteLastNode(&head);
    printf("After deleting the last node: ");
    displayList(head);

    // Delete a specific node from the circular header linked list
    int value = 3;
    deleteNode(&head, value);
    printf("After deleting node with value %d: ", value);
    displayList(head);

    return 0;
}
