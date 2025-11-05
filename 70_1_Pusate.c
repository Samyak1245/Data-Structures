//1. Program to implement stack using array
//Roll Number: 70

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("\nStack Overflow");
    } else {
        top++;
        stack[top] = val;
        printf("\n%d pushed into the stack.", val);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow");
    } else {
        printf("\n%d popped from the stack.", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty.");
    } else {
        printf("\nStack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter val to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExit");
                return 0;
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}
