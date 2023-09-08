// Q8: Write a program to implement a DEQUE (Double Ended Queue) using a doubly
// linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

Node *front = NULL;
Node *rear = NULL;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void push_front(int data) {
    Node *new_node = create_node(data);
    if (front) {
        new_node->next = front;
        front->prev = new_node;
        front = new_node;
    } else {
        front = rear = new_node;
    }
}

void push_rear(int data) {
    Node *new_node = create_node(data);
    if (rear) {
        new_node->prev = rear;
        rear->next = new_node;
        rear = new_node;
    } else {
        front = rear = new_node;
    }
}

int pop_front() {
    if (!front) {
        printf("deque is empty. Cannot pop from front\n");
        return -1;
    }
    int data = front->data;
    Node *temp = front;
    front = front->next;
    if (front) {
        front->prev = NULL;
    } else {
        rear = NULL; // Empty DEQUE
    }
    free(temp);
    return data;
}

int pop_rear() {
    if (!rear) {
        printf("deque is empty. Cannot pop from rear\n");
        return -1;
    }
    int data = rear->data;
    Node *temp = rear;
    rear = rear->prev;
    if (rear) {
        rear->next = NULL;
    } else {
        front = NULL; // Empty DEQUE
    }
    free(temp);
    return data;
}

void display() {
    Node *current = front;
    printf("Deque: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push_rear(1); // Push 1 to the rear
    push_front(2); // Push 2 to the front
    push_rear(3); // Push 3 to the rear
    push_front(4); // Push 4 to the front

    display();

    printf("Popped from front: %d\n", pop_front());
    printf("Popped from rear: %d\n", pop_rear());

    display();

    return 0;
}
