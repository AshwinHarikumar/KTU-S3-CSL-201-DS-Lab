#include<stdio.h>
#define MAX 5
int queue[MAX];
void enqueue();
void dequeue();
void display();
int front=-1;
int rear=-1;
int item;
void main()
{
int ch,max;
printf("enter the maximum size of array");
scanf("%d",&max);
while(ch!=4)
{
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
scanf("%d",&ch);

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
printf("Exiting");
break;
default:printf("Invalid choice");
}
}
}

void enqueue()
{
if(rear>=MAX-1)
{
printf("overflow");
}
else
{
printf("enter the item to be inserrted to array");
scanf("%d",&item);
if(front==-1&&rear==-1)
{
front=0;
rear=0;
//queue[rear]=item;
}
else
{
rear=rear+1;
}
queue[rear]=item;
printf("inserted %d",item);
}
}
void dequeue()
{
if(front==-1&&rear==-1)
{
printf("underflow");
}
else 

{
if(front==rear)
{
item=queue[front];
front=-1;
rear=-1;
}
else
{
front=front+1;
}
item=queue[front];
printf("%d element was deleted",item);
}
}
void display()
{
if (front==-1)
{
printf("queue is empty");
}
else
{

for(int i=front;i<=rear;i++)
{
printf("%d \n",queue[i]);
}
}
}










































