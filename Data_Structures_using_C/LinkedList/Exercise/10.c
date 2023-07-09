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

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Function to create a new linked list from every alternate element of the existing linked list
struct Node* createNewList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct Node* newHead = NULL;
    struct Node* newTail = NULL;
    struct Node* temp = head;

    int count = 0;
    while (temp != NULL) {
        if (count % 2 == 0) {
            // Add the alternate element to the new list
            if (newHead == NULL) {
                newHead = createNode(temp->data);
                newTail = newHead;
            } else {
                newTail->next = createNode(temp->data);
                newTail = newTail->next;
            }
        }
        count++;
        temp = temp->next;
    }

    return newHead;
}

int main() {
    struct Node* originalList = NULL;
    struct Node* newList = NULL;

    // Insert nodes into the original linked list
    insertNode(&originalList, 1);
    insertNode(&originalList, 2);
    insertNode(&originalList, 3);
    insertNode(&originalList, 4);
    insertNode(&originalList, 5);

    // Display the original list
    printf("Original List: ");
    displayList(originalList);

    // Create a new list from every alternate element of the original list
    newList = createNewList(originalList);

    // Display the new list
    printf("New List: ");
    displayList(newList);

    return 0;
}
