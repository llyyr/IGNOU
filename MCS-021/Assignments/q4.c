// Q4: Implement a Circular Queue with enqueue and dequeue functions.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} CQ;

int is_empty(const CQ *cq) {
    return (cq->front == -1);
}

int is_full(const CQ *cq) {
    return ((cq->rear + 1) % MAX_SIZE == cq->front);
}

void enqueue(CQ *cq, int item) {
    if (is_full(cq)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->data[cq->rear] = item;
    if (is_empty(cq))
        cq->front = cq->rear;
    printf("Enqueued %d into the queue\n", item);
}

int dequeue(CQ *cq) {
    if (is_empty(cq)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    int item = cq->data[cq->front];
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    return item;
}

void display(const CQ *cq) {
    if (is_empty(cq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = cq->front; i != cq->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", cq->data[i]);
    printf("%d\n", cq->data[cq->rear]);
}

int main() {
    CQ cq;
    cq.front = cq.rear = -1;
    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    enqueue(&cq, 4);
    enqueue(&cq, 5);
    display(&cq);
    int removed = dequeue(&cq);
    if (removed != -1)
        printf("Dequeued %d from the queue.\n", removed);
    display(&cq);
    enqueue(&cq, 6);
    display(&cq);
    return 0;
}
