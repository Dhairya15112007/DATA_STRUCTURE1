#include <stdio.h>

#define MAX_SIZE 100

void print_array(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    putchar('\n');
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }

        /* Stop early if the array is already sorted. */
        if (!swapped) {
            break;
        }
    }
}

void selection_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int main(void) {
    int original[MAX_SIZE];
    int bubble_array[MAX_SIZE];
    int selection_array[MAX_SIZE];
    int size;

    printf("Enter the number of elements (1-%d): ", MAX_SIZE);

    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d integers: ", size);

    for (int i = 0; i < size; i++) {
        if (scanf("%d", &original[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    for (int i = 0; i < size; i++) {
        bubble_array[i] = original[i];
        selection_array[i] = original[i];
    }

    bubble_sort(bubble_array, size);
    selection_sort(selection_array, size);

    printf("\nOriginal array:  ");
    print_array(original, size);

    printf("Bubble sort:     ");
    print_array(bubble_array, size);

    printf("Selection sort:  ");
    print_array(selection_array, size);

    return 0;
}