// Q4: Write a program to implement doubly linked list for user inputs. 
// Also, perform insertion and deletion operations on it

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;
Node *head = NULL;

void insert(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;
    if (head)
        head->prev = new_node;
    head = new_node;
}

void delete(int data) {
    Node *current = head;
    while (current) {
        if (current->data == data) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next)
                current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list\n", data);
}

void display() {
    Node *current = head;
    printf("List: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\nChoose an operation:\n"
               "1. Insert\n"
               "2. Delete\n"
               "3. Display\n"
               "4. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
