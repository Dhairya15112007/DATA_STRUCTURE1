#include <stdio.h>

int main()
{
    int a[100], n, i, pos, value, key, found = 0, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Traversal\n2. Insertion\n3. Deletion\n4. Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Array elements: ");
            for(i = 0; i < n; i++)
                printf("%d ", a[i]);
            break;

        case 2:
            printf("Enter position and value: ");
            scanf("%d%d", &pos, &value);

            for(i = n; i >= pos; i--)
                a[i] = a[i - 1];

            a[pos - 1] = value;
            n++;

            printf("Array after insertion: ");
            for(i = 0; i < n; i++)
                printf("%d ", a[i]);
            break;

        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            for(i = pos - 1; i < n - 1; i++)
                a[i] = a[i + 1];

            n--;

            printf("Array after deletion: ");
            for(i = 0; i < n; i++)
                printf("%d ", a[i]);
            break;

        case 4:
            printf("Enter element to search: ");
            scanf("%d", &key);

            for(i = 0; i < n; i++)
            {
                if(a[i] == key)
                {
                    printf("Element found at position %d", i + 1);
                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("Element not found");
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}