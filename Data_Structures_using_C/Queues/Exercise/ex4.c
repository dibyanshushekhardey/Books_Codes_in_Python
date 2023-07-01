#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

void initDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = deque->rear;
    newNode->next = NULL;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }

    struct Node* temp = deque->front;
    int data = temp->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Error: Deque is empty\n");
        return -1;
    }

    struct Node* temp = deque->rear;
    int data = temp->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

int main() {
    struct Deque myDeque;
    initDeque(&myDeque);

    insertFront(&myDeque, 10);
    insertFront(&myDeque, 20);
    insertRear(&myDeque, 30);
    insertRear(&myDeque, 40);

    printf("Values in the deque (Front to Rear):\n");
    while (!isEmpty(&myDeque)) {
        int value = deleteFront(&myDeque);
        printf("%d ", value);
    }
    printf("\n");

    insertFront(&myDeque, 50);
    insertRear(&myDeque, 60);
    insertFront(&myDeque, 70);
    insertRear(&myDeque, 80);

    printf("Values in the deque (Rear to Front):\n");
    while (!isEmpty(&myDeque)) {
        int value = deleteRear(&myDeque);
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
