#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;

    if((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = value;

        printf("Element inserted\n");
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");

        i = front;

        while(1)
        {
            printf("%d ", queue[i]);

            if(i == rear)
                break;

            i = (i + 1) % MAX;
        }
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