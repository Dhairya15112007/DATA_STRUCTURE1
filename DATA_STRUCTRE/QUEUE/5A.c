#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;

    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("Element inserted\n");
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements: ");

        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    } while(choice != 4);

    return 0;
}