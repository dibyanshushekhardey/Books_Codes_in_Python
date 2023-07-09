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

// Function to merge two linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = list2;

    return list1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    // Insert nodes into list1
    insertNode(&list1, 1);
    insertNode(&list1, 2);
    insertNode(&list1, 3);

    // Insert nodes into list2
    insertNode(&list2, 4);
    insertNode(&list2, 5);
    insertNode(&list2, 6);

    // Display list1
    printf("List 1: ");
    displayList(list1);

    // Display list2
    printf("List 2: ");
    displayList(list2);

    // Merge list1 and list2
    mergedList = mergeLists(list1, list2);

    // Display the merged list
    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}
