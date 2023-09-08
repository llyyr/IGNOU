// Q2: Write a program to implement singly linked list for user inputs. 
// Also, perform insertion and delete operation on it.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;

void insert(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d into the list.\n", data);
}

void delete(int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted %d from the list.\n", data);
        return;
    }
    Node *current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("%d not found in the list.\n", data);
    } else {
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
        printf("Deleted %d from the list.\n", data);
    }
}

void display() {
    Node *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
