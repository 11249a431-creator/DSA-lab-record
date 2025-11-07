#include <stdio.h>
#define MAX 100 // Maximum size of stack

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
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

// Push element onto stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("Pushed %d\n", value);
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1; // Return -1 to indicate error
    }
    return s->arr[(s->top)--];
}

// Peek top element of stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack s;
    init(&s); // Initialize stack
    push(&s, 10); // Push elements onto stack
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s)); // Peek top element
    printf("Popped element is %d\n", pop(&s)); // Pop an element
    printf("Popped element is %d\n", pop(&s)); // Pop another element

    if (isEmpty(&s)) { // Check if stack is empty
        printf("Stack is empty now\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}

