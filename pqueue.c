#include <stdio.h>
#define MAX 3

int rear = -1;
int front = -1;

struct priority {
    int item;
    int priority;
} pqueue[MAX];

void enqueue(int data, int p);
void dequeue();
void sort();
void display();

int main() {
    int ch = 0, data, p;

    while (ch != 4) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (rear >= MAX - 1) {
                    printf("Overflow\n");
                } else {
                    printf("Enter data: ");
                    scanf("%d", &data);
                    printf("Enter priority: ");
                    scanf("%d", &p);
                    enqueue(data, p);
                }
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void enqueue(int data, int p) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    pqueue[rear].item = data;
    pqueue[rear].priority = p;
    sort();
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else {
        printf("Dequeued item: %d with priority: %d\n", pqueue[front].item, pqueue[front].priority);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void sort() {
    struct priority temp;
    for (int i = front; i < rear; i++) {
        for (int j = front; j < rear - i + front; j++) {
            if (pqueue[j].priority > pqueue[j + 1].priority) {
                temp = pqueue[j];
                pqueue[j] = pqueue[j + 1];
                pqueue[j + 1] = temp;
            }
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("Item: %d Priority: %d\n", pqueue[i].item, pqueue[i].priority);
        }
    }
}
