#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("\tStack is full (overflow)\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\tPushed %d to stack\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty (underflow)\n");
    }
    else
    {
        int removed = stack[top];
        top--;
        printf("Popped %d from stack\n", removed);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n\t1. Push\n\t2. Pop\n\t3. Peek (Top)\n\t4. Display\n\t5. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("\n\tInvalid choice!\n");
        }
    }
}

