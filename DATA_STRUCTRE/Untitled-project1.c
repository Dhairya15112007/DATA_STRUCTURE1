#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    char user[30];
    char document[30];
    int pages;
    struct Job *next;
};

struct Job *front = NULL;
struct Job *rear = NULL;
int nextId = 1;

int isEmpty() {
    return front == NULL;
}

void addJob() {
    struct Job *newJob = (struct Job *)malloc(sizeof(struct Job));
    if (newJob == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newJob->id = nextId++;

    printf("Enter user name (one word): ");
    scanf("%s", newJob->user);
    printf("Enter document name (one word): ");
    scanf("%s", newJob->document);
    printf("Enter number of pages: ");
    scanf("%d", &newJob->pages);
    newJob->next = NULL;

    if (rear == NULL) {
        front = newJob;
        rear = newJob;
    } else {
        rear->next = newJob;
        rear = newJob;
    }

    printf("Job added. Job ID = %d\n", newJob->id);
}

void printJob() {
    if (isEmpty()) {
        printf("No jobs in the queue.\n");
        return;
    }

    struct Job *temp = front;
    printf("\nPrinting Job ID %d | User: %s | Document: %s | Pages: %d\n",
           temp->id, temp->user, temp->document, temp->pages);
    printf("Job completed.\n");

    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue() {
    if (isEmpty()) {
        printf("No pending jobs.\n");
        return;
    }

    struct Job *temp = front;
    printf("\n%-6s %-14s %-14s %-6s\n", "ID", "User", "Document", "Pages");
    printf("------------------------------------------\n");
    while (temp != NULL) {
        printf("%-6d %-14s %-14s %-6d\n",
               temp->id, temp->user, temp->document, temp->pages);
        temp = temp->next;
    }
}

void cancelJob() {
    if (isEmpty()) {
        printf("No jobs to cancel.\n");
        return;
    }

    int id;
    printf("Enter Job ID to cancel: ");
    scanf("%d", &id);

    struct Job *curr = front;
    struct Job *prev = NULL;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Job ID %d not found.\n", id);
        return;
    }

    if (prev == NULL)
        front = curr->next;
    else
        prev->next = curr->next;

    if (curr == rear)
        rear = prev;

    free(curr);
    printf("Job ID %d cancelled.\n", id);
}

int main() {
    int choice;

    do {
        printf("\n===== PRINTER JOB SCHEDULING =====\n");
        printf("1. Add Print Job\n");
        printf("2. Print Next Job\n");
        printf("3. Display Pending Jobs\n");
        printf("4. Cancel a Job\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addJob(); break;
            case 2: printJob(); break;
            case 3: displayQueue(); break;
            case 4: cancelJob(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    while (!isEmpty()) {
        struct Job *temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}