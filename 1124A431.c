#include <stdio.h>
#include <ctype.h>  // for isalpha() and isdigit()
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element onto the stack
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = c;
    }
}

// Pop element from the stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';  // Stack is empty
}

// Peek the top element of the stack without removing it
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

// Check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int k = 0;  // Index for postfix

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If operand (letter or digit), add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(&s, c);
        }
        // If ')', pop and output until '('
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Remove '(' from stack
        }
        // If operator
        else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                if (c == '^' && peek(&s) == '^') {
                    // Right associative operator '^' should not pop same precedence operator
                    break;
                } else {
                    postfix[k++] = pop(&s);
                }
            }
            push(&s, c);
        }
    }

    // Pop all remaining operators
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';  // Null-terminate postfix string
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    // Read infix expression
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove trailing newline character from fgets input
    infix[strcspn(infix, "\n")] = '\0';

    // Convert to postfix
    infixToPostfix(infix, postfix);

    // Output postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
