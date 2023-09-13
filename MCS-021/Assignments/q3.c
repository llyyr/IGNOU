// Q3: Write a C program to implement a doubly linked list. Also, write functions
// to perform insertion and deletion operations in it.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

void insert(int data, int pos) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (!head) {
        head = new;
        return;
    }

    if (pos == -1) {
        // Insert at the end
        Node *cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = new;
        new->prev = cur;
    } else if (pos == 0) {
        // Insert at the beginning
        new->next = head;
        head->prev = new;
        head = new;
    } else {
        // Insert at a specific pos
        Node *cur = head;
        int cur_pos = 0;
        while (cur->next && cur_pos < pos - 1) {
            cur = cur->next;
            cur_pos++;
        }
        new->next = cur->next;
        if (cur->next)
            cur->next->prev = new;
        new->prev = cur;
        cur->next = new;
    }
}

void delete(int data) {
    Node *cur = head;
    while (cur) {
        if (cur->data == data) {
            if (cur->prev) {
                cur->prev->next = cur->next;
            } else {
                head = cur->next;
            }
            if (cur->next)
                cur->next->prev = cur->prev;
            free(cur);
            return;
        }
        cur = cur->next;
    }
    printf("%d not found in the list\n", data);
}

void display() {
    Node *cur = head;
    printf("List: ");
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    insert(10, -1);
    insert(12, 0);
    insert(14, 1);
    insert(15, 1);
    display();
    delete(14);
    display();
    free(head);
    return 0;
}
