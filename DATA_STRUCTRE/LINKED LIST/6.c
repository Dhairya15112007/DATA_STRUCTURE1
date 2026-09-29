#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *start = NULL;


void insert_begin()
{
    int x;
    struct node *temp;

    printf("Enter value: ");
    scanf("%d", &x);

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = x;
    temp->next = start;
    start = temp;

    printf("Node inserted at beginning.\n");
}


void insert_end()
{
    int x;
    struct node *temp, *p;

    printf("Enter value: ");
    scanf("%d", &x);

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = x;
    temp->next = NULL;

    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        p = start;

        while(p->next != NULL)
            p = p->next;

        p->next = temp;
    }

    printf("Node inserted at end.\n");
}


void insert_after()
{
    int key, x;
    struct node *p, *temp;

    printf("Enter node value after which to insert: ");
    scanf("%d", &key);

    p = start;

    while(p != NULL && p->info != key)
        p = p->next;

    if(p == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = x;
    temp->next = p->next;
    p->next = temp;

    printf("Node inserted.\n");
}


void delete_begin()
{
    struct node *temp;

    if(start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = start;
    start = start->next;

    free(temp);

    printf("First node deleted.\n");
}


void delete_end()
{
    struct node *p, *temp;

    if(start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if(start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        p = start;

        while(p->next->next != NULL)
            p = p->next;

        temp = p->next;
        p->next = NULL;

        free(temp);
    }

    printf("Last node deleted.\n");
}


void delete_after()
{
    int key;
    struct node *p, *temp;

    printf("Enter node value after which to delete: ");
    scanf("%d", &key);

    p = start;

    while(p != NULL && p->info != key)
        p = p->next;

    if(p == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    if(p->next == NULL)
    {
        printf("No node exists after this node.\n");
        return;
    }

    temp = p->next;
    p->next = temp->next;

    free(temp);

    printf("Node deleted.\n");
}


void display()
{
    struct node *p;

    if(start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = start;

    printf("Linked List: ");

    while(p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->next;
    }

    printf("NULL\n");
}


int main()
{
    int choice;

    do
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after given node\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Delete node after given node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_after();
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                delete_after();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 8);

    return 0;
}