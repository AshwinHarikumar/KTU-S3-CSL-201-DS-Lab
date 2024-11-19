#include <stdio.h>
#define MAX 3
int queue[MAX];
int front = -1;
int rear = -1;
int item;
void enqueue();
void dequeue();
void display();
void main() 
{
    int ch;
    while (ch != 4) 
    {
        printf("\n1. enqueue\n2. dequeue\n3. display\n4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
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
                printf("Exiting...\n");
                break;      
            default: 
                printf("Invalid choice\n");
        }
    }
}
void enqueue()
 {
    if ((rear + 1) % MAX == front) 
    {
        printf("Overflow\n");
    } 
    else
     {
        printf("Insert the element in queue: ");
        scanf("%d", &item);
        if (front == -1 && rear == -1) 
        {
        queue[rear] = item;
            front = rear = 0;
        } 
        else
        {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = item;
        printf("Inserted %d\n", item);
    }
}
void dequeue() 
{
    if (front ==-1&& rear==-1) 
    {
        printf("Underflow\n");
    } 
    else
     {
        
        if (front == rear)
         { int item = queue[front];
            front = rear = -1;
        } 
        else
         {
            front = (front + 1) % MAX;
        }
        int item = queue[front];
        printf("Deleted %d\n", item);
    }
}
void display()
 {
    if (front == -1) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        printf("Queue elements are: ");
        int i = front;
        while (i != rear)
         {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d",queue[i]);
    }
}
