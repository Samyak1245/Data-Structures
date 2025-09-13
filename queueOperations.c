#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("\nQueue is Full");
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
        printf("\nEnqueued %d\n", val);
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is full");
        front = rear = -1;
    }
    else
        printf("\nDequeued %d", queue[front]);
    front++;
}

void peep()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is full");
    }
    else
    {
        printf("\nFront element is %d", queue[front]);
    }
}

void display()
{

    if (front == -1 || front > rear)
    {
        printf("\nQueue is full");
    }
    else
    {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice, val;
    while (1)
    {

        printf("\n1. Enqueue\n2. Dequeue\n3. Peep\n4. Display\n5. Exit");
        printf("\nEnter the choice:   ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peep();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}