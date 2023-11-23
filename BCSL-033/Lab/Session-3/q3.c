#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
Node* insert_beginning(Node* head, int data) {
    Node* new_node = create_node(data);
    new_node->next = head;
    return new_node;
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


// Function to insert a node into a sorted list
Node* insert_sorted(Node* head, Node* new_node) {
    if (head == NULL || head->data >= new_node->data) {
        new_node->next = head;
        return new_node;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data < new_node->data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return head;
}

// Function to sort the linked list in ascending order
Node* sort_list(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* sorted = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* next = current->next;
        sorted = insert_sorted(sorted, current);
        current = next;
    }

    return sorted;
}

int main() {
    // Input list
    Node* list = NULL;
    list = insert_beginning(list, 3);
    list = insert_beginning(list, 1);
    list = insert_beginning(list, 4);
    list = insert_beginning(list, 2);

    // Print original list
    printf("Original List: ");
    print_list(list);

    // Sort the list
    list = sort_list(list);
    printf("Sorted List: ");
    print_list(list);

    // Accept an integer as input
    int new_data;
    printf("Enter an integer to insert: ");
    scanf("%d", &new_data);

    // Insert the integer at the appropriate position
    Node* new_node = create_node(new_data);
    list = insert_sorted(list, new_node);

    // Print the updated list
    printf("Updated List: ");
    print_list(list);

    // Free memory
    free(list);

    return 0;
}


