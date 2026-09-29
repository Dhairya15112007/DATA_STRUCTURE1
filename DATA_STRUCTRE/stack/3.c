#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("Element pushed\n");
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display()
{
    int i;

    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements:\n");

        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
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
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    } while(choice != 5);

    return 0;
}