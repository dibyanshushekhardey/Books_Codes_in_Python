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

int compareQueues(struct Queue* queue1, struct Queue* queue2) {
    if (queue1->front == -1 && queue2->front == -1) {
        return 0; // Both queues are empty
    }

    if ((queue1->front == -1 && queue2->front != -1) || (queue1->front != -1 && queue2->front == -1)) {
        return 1; // One queue is empty and the other is not
    }

    if (queue1->rear - queue1->front != queue2->rear - queue2->front) {
        return 1; // Queues have different sizes
    }

    int i, j;
    for (i = queue1->front, j = queue2->front; i <= queue1->rear; i++, j++) {
        if (queue1->items[i] != queue2->items[j]) {
            return 1; // Queues have different elements
        }
    }

    return 0; // Queues are identical
}

int main() {
    struct Queue queue1, queue2;
    initQueue(&queue1);
    initQueue(&queue2);

    int n1, n2, i, data;

    printf("Enter the number of elements for queue 1: ");
    scanf("%d", &n1);

    printf("Enter the elements for queue 1: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &data);
        enqueue(&queue1, data);
    }

    printf("Enter the number of elements for queue 2: ");
    scanf("%d", &n2);

    printf("Enter the elements for queue 2: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &data);
        enqueue(&queue2, data);
    }

    int result = compareQueues(&queue1, &queue2);

    if (result == 0) {
        printf("The queues are identical\n");
    } else {
        printf("The queues are different\n");
    }

    return 0;
}
