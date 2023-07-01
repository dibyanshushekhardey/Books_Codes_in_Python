#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Error: Stack is full\n");
        return;
    }

    stack->top++;
    stack->items[stack->top] = data;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }

    int data = stack->items[stack->top];
    stack->top--;

    return data;
}

struct Queue {
    struct Stack inbox;
    struct Stack outbox;
};

void initQueue(struct Queue* queue) {
    initStack(&(queue->inbox));
    initStack(&(queue->outbox));
}

int isQueueEmpty(struct Queue* queue) {
    return (isEmpty(&(queue->inbox)) && isEmpty(&(queue->outbox)));
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(&(queue->inbox))) {
        printf("Error: Queue is full\n");
        return;
    }

    while (!isEmpty(&(queue->outbox))) {
        int item = pop(&(queue->outbox));
        push(&(queue->inbox), item);
    }

    push(&(queue->inbox), data);
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    while (!isEmpty(&(queue->inbox))) {
        int item = pop(&(queue->inbox));
        push(&(queue->outbox), item);
    }

    return pop(&(queue->outbox));
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Values in the queue:\n");
    while (!isQueueEmpty(&myQueue)) {
        int value = dequeue(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
