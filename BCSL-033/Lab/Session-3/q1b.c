#include <stdio.h>
#include <stdlib.h>

// Define macro for circular doubly linked list
#define CIRCULAR

// Define the structure for a Node
struct Node {
    int data;
    struct Node* prev;  // Previous pointer for doubly linked list
    struct Node* next;  // Next pointer
};

typedef struct Node Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


Node* insert(Node* head, int data) {
    Node* new_node = create_node(data);

    // Insertion for non-circular linked list
    #ifndef CIRCULAR
        if (head == NULL) {
            return new_node;
        }

        new_node->next = head;
        new_node->prev = NULL;  // In a non-circular doubly linked list, the previous pointer of the first node should be NULL.
        if (head != NULL) {
            head->prev = new_node;
        }
        return new_node;
    #else
    // Insertion for circular linked list
        if (head == NULL) {
            new_node->next = new_node;
            new_node->prev = new_node;
            return new_node;
        }

        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        return head;
    #endif
}

Node* delete_element(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* current = head;
    Node* prev = NULL;

    do {
        if (current->data == key) {
            // Deletion for non-circular linked list
            #ifndef CIRCULAR
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                }
                if (head == current) {
                    head = current->next;
                }
            #else
            // Deletion for circular linked list
                if (current->next == current) {
                    free(current);
                    return NULL;  // List becomes empty
                } else {
                    if (prev != NULL) {
                        prev->next = current->next;
                    }
                    if (head == current) {
                        head = current->next;
                    }
                    current->next->prev = prev;
                }
            #endif

            free(current);
            printf("Element %d deleted successfully.\n", key);
            return head;
        }

        prev = current;
        current = current->next;

    } while (current != head);

    printf("Element not found in the list.\n");
    return head;
}

// Function to display the linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;

    // Display for non-circular linked list
    #ifndef CIRCULAR
        while (current != NULL) {
            printf("%d", current->data);
            current = current->next;
            if (current != NULL) {
                printf(" <-> ");
            }
        }
    #else

    // Display for circular linked list
        printf("Tail <-> ");
        Node* start = current;
        do {
            printf("%d", current->data);
            current = current->next;
            if (current != start) {
                printf(" <-> ");
            }
        } while (current != NULL && current != start);
        printf(" <-> Head");
    #endif

    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert elements
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    // Display original list
    printf("Original List: ");
    display(head);

    // Delete an element
    head = delete_element(head, 20);

    // Display updated list
    printf("Updated List: ");
    display(head);

    return 0;
}
