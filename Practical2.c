#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x)
{
    stack1[++top1] = x;
}

int pop1()
{
    return stack1[top1--];
}

void push2(int x)
{
    stack2[++top2] = x;
}

int pop2()
{
    return stack2[top2--];
}

void enqueue(int x)
{

    while (top1 != -1)
    {
        push2(pop1());
    }

    push1(x);

    while (top2 != -1)
    {
        push1(pop2());
    }

    printf("Enqueued: %d\n", x);
}

void dequeue()
{
    if (top1 == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    int val = pop1();
    printf("Dequeued: %d\n", val);
}

void display()
{
    if (top1 == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }
}

int main()
{
    int choice, val;

    while (1)
    {
        printf("\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}