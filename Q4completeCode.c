#include <stdio.h>
#define MAXSIZE 5

void push(int stack[], int *top, int maxSize) {
    if (*top == maxSize - 1) {
        printf("Stack Overflow!\n");
    } else {
        int value;
        printf("Enter value to push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow!\n");
    } else {
        int value = stack[*top];
        (*top)--;
        printf("%d removed from stack.\n", value);
    }
}

void peek(int stack[], int top) {
    if (top == -1)
        printf("Stack is empty.\n");
    else
        printf("Top element is: %d\n", stack[top]);
}

void display(int stack[], int top) {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[MAXSIZE];
    int top = -1;
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(stack, &top, MAXSIZE); break;
            case 2: pop(stack, &top); break;
            case 3: peek(stack, top); break;
            case 4: display(stack, top); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
