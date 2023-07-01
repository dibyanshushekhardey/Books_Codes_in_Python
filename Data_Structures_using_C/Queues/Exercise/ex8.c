#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct PriorityQueue {
    int items[MAX_SIZE];
    int priorities[MAX_SIZE];
    int front;
    int rear;
};

void initPriorityQueue(struct PriorityQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct PriorityQueue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct PriorityQueue* queue) {
    return (queue->front == -1);
}

void enqueue(struct PriorityQueue* queue, int data, int priority) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    int i;
    for (i = queue->rear; i >= 0; i--) {
        if (priority > queue->priorities[i]) {
            queue->items[i + 1] = queue->items[i];
            queue->priorities[i + 1] = queue->priorities[i];
        } else {
            break;
        }
    }

    queue->items[i + 1] = data;
    queue->priorities[i + 1] = priority;

    queue->rear++;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

int dequeue(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
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

int main() {
    struct PriorityQueue myQueue;
    initPriorityQueue(&myQueue);

    enqueue(&myQueue, 10, 2);
    enqueue(&myQueue, 20, 1);
    enqueue(&myQueue, 30, 3);
    enqueue(&myQueue, 40, 2);

    printf("Values in the priority queue:\n");
    while (!isEmpty(&myQueue)) {
        int value = dequeue(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
