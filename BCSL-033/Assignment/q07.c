// Q7: Write a program to implement two stacks with the help of single array

#include <stdio.h>

#define MAX_SIZE 10

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

typedef struct Stack Stack;

void push(Stack *stack, int data) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++stack->top] = data;
    } else {
        printf("Stack is full. Cannot push\n");
    }
}

int pop(Stack *stack) {
    int data = -1;
    if (stack->top >= 0) {
        data = stack->arr[stack->top--];
    } else {
        printf("Stack is empty. Cannot pop\n");
    }
    return data;
}

int main() {
    Stack stacks[2];
    stacks[0].top = -1;
    stacks[1].top = -1;

    push(&stacks[0], 1);
    push(&stacks[0], 2);

    push(&stacks[1], 3);
    push(&stacks[1], 4);
    push(&stacks[1], 5);

    printf("Popped from Stack 0: %d\n", pop(&stacks[0]));
    printf("Popped from Stack 1: %d\n", pop(&stacks[1]));

    return 0;
}
