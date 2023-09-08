// Q9: Write a program to convert an infix expression to a postfix expression.
// Use appropriate data  structure.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

struct Stack {
    int top;
    char items[MAX_STACK_SIZE];
};

typedef struct Stack Stack;

void push(Stack* stack, char item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int precedence(char c) {
    return (c == '+' || c == '-') ? 1 :
           (c == '*' || c == '/') ? 2 :
            0;
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];
        if (c == ' ' || c == '\t') {
            i++;
        } else if (isdigit(c) || isalpha(c)) {
            postfix[j++] = c;
            i++;
        } else if (c == '(') {
            push(&stack, c);
            i++;
        } else if (c == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top != -1 && stack.items[stack.top] == '(') {
                pop(&stack);
            }
            i++;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (stack.top != -1 && stack.items[stack.top] != '(' &&
                   precedence(c) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
            i++;
        } else {
            printf("Invalid character in infix expression: %c\n", c);
            exit(1);
        }
    }

    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_STACK_SIZE];
    char postfix[MAX_STACK_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
