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
if((rear+1)%MAX==front)
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

}
else
{
rear=(rear+1)%MAX;
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
front=(front+1)%MAX;
}
item=queue[front];
printf("%d element was deleted",item);
}
}
void display()
{
if(front==-1)
{
printf("empty queue");
}
else
{
printf("queue elements are: ");
int i=front;
while(i!=rear)
{
printf("%d\t",queue[i]);
i=(i+1)%MAX;
}
printf("\n");
}
}










































