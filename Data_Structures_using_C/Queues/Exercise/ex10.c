#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isQueueEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int data) {
    if (isQueueFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = data;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = queue->items[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return data;
}

struct Stack {
    struct Queue queue;
};

void initStack(struct Stack* stack) {
    initQueue(&(stack->queue));
}

int isStackEmpty(struct Stack* stack) {
    return isQueueEmpty(&(stack->queue));
}

void push(struct Stack* stack, int data) {
    enqueue(&(stack->queue), data);
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }

    struct Queue tempQueue;
    initQueue(&tempQueue);

    while (stack->queue.front != stack->queue.rear) {
        int data = dequeue(&(stack->queue));
        enqueue(&tempQueue, data);
    }

    int poppedData = dequeue(&(stack->queue));

    while (!isQueueEmpty(&tempQueue)) {
        int data = dequeue(&tempQueue);
        enqueue(&(stack->queue), data);
    }

    return poppedData;
}

int main() {
    struct Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Values in the stack:\n");
    while (!isStackEmpty(&myStack)) {
        int value = pop(&myStack);
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
