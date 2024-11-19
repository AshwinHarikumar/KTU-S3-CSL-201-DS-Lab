#include <stdio.h>
#define MAX 3
int deque[MAX];
int front = -1;
int rear = -1;
int ch,n;
void enqueuefront(int n);
void enqueuerear(int n);
void dequeuefront(int n);
void dequeuerear(int n);
void display();
void main()
{
while (ch != 6)
{
printf("\n1.Enqueue Rear\n2.Enqueue Front\n3.Dequeue Front\n4.Dequeue Rear\n5.Display\n6.Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:printf("Enter the element to push at front: ");
scanf("%d", &n);
enqueuerear(n);
break;
case 2:printf("Enter the element to push at rear: ");
scanf("%d", &n);
enqueuefront(n);
break;
case 3:dequeuefront(n);
break;
case 4:dequeuerear(n);
break;
case 5:display();
break;
case 6:printf("EXITING.......\n");
break;
default:printf("INVALID CHOICE\n");
}
}
}
void enqueuerear(int n)
{
if(rear>=MAX-1)
{
printf("ENQUEUE OVERFLOW\n");
}
else
{
if (front==-1)
{
front=rear=0;
}
else
{
rear++;
}
deque[rear]=n;
printf("INSERTED %d AT REAR\n",n);
}
}
void enqueuefront(int n)
{
if(front<=0)
{

printf("ENQUEUE OVERFLOW\n");
}
else
{
front--;
deque[front] = n;
printf("INSERTED %d AT FRONT\n",n);
}
}
void dequeuefront(int n)
{
if(front==-1&&rear==-1)
{
printf("DEQUEUE UNDERFLOW\n");
}
else
{
printf("REMOVED %d FROM FRONT\n", deque[front]);
if (front == rear)
{
front=rear=-1;
}
else
{
n=deque[front];
front=front+1;
}
}
}
void dequeuerear(int n)
{
if (rear==-1)
{
printf("DEQUEUE UNDERFLOW\n");
}
else
{
printf("REMOVED %d FROM REAR\n",deque[rear]);
if (front==rear)
{
n=deque[front];
front=rear=-1;
}
else
{
n=deque[front];
rear--;
}
}
}
void display()
{
if (front==-1)
{

printf("DEQUEUE IS EMPTY\n");
}
else
{
printf("QUEUE ELEMENTS ARE : ");
int i = front;
while (ch!=6)
{
printf("%d ", deque[i]);
if (i == rear)
break;
i = (i + 1) % MAX;
}
printf("\n");
}
}
	

