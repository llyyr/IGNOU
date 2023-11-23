#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the list
Node* insert_end(Node* head, int data) {
    Node* new_node = create_node(data);

    if (head == NULL) {
        return new_node;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

// Function to print the linked list
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// Function to find and print common elements in two linked lists
void print_common_elements(Node* list_a, Node* list_b) {
    Node* current_a = list_a;
    while (current_a != NULL) {
        Node* current_b = list_b;
        while (current_b != NULL) {
            if (current_a->data == current_b->data) {
                printf("%d", current_a->data);
                if (current_a->next != NULL) {
                    printf(" -> ");
                }
                break;  // Move to the next element in list A
            }
            current_b = current_b->next;
        }
        current_a = current_a->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Input list A
    Node* list_a = NULL;
    list_a = insert_end(list_a, 1);
    list_a = insert_end(list_a, 2);
    list_a = insert_end(list_a, 3);
    list_a = insert_end(list_a, 4);

    // Input list B
    Node* list_b = NULL;
    list_b = insert_end(list_b, 3);
    list_b = insert_end(list_b, 4);
    list_b = insert_end(list_b, 5);
    list_b = insert_end(list_b, 6);

    // Print input lists
    printf("List A: ");
    print_list(list_a);
    printf("List B: ");
    print_list(list_b);

    // Print common elements
    printf("Common Elements: ");
    print_common_elements(list_a, list_b);

    // Free memory
    free_list(list_a);
    free_list(list_b);

    return 0;
}
