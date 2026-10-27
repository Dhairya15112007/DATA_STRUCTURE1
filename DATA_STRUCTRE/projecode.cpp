#include <iostream>
#include <string>
using namespace std;

#define MAX 5

struct Job {
    int id;
    string user;
    string doc;
    int pages;
};

class Queue {
    Job jobs[MAX];
    int front;
    int count;
public:
    Queue() {
        front = 0;
        count = 0;
    }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == MAX; }

    void enqueue(Job j) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        jobs[(front + count) % MAX] = j;
        count++;
        cout << "Job " << j.id << " added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No jobs to print.\n";
            return;
        }
        Job j = jobs[front];
        cout << "Printing Job " << j.id << ": " << j.doc << " (" << j.pages << " pages) for " << j.user << "\n";
        front = (front + 1) % MAX;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending jobs.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            Job j = jobs[(front + i) % MAX];
            cout << i + 1 << ". " << j.id << " | " << j.user << " | " << j.doc << " | " << j.pages << " pages\n";
        }
    }
};

int main() {
    Queue q;
    int ch = 0;
    while (ch != 4) {
        cout << "\n1.Add Job  2.Print Next Job  3.Display Jobs  4.Exit\nChoice: ";
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(1000, '\n');
            ch = 0;
            cout << "Invalid choice.\n";
            continue;
        }
        if (ch == 1) {
            Job j;
            cout << "Job ID: ";    cin >> j.id;
            cout << "User: ";      cin >> j.user;
            cout << "Document: ";  cin >> j.doc;
            cout << "Pages: ";     cin >> j.pages;
            q.enqueue(j);
        }
        else if (ch == 2) q.dequeue();
        else if (ch == 3) q.display();
        else if (ch != 4) cout << "Invalid choice.\n";
    }
    return 0;
}
