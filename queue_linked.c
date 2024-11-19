#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *front=NULL,*rear=NULL,*current,*newnode;
void enqueue()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (newnode==NULL)
    {
        printf("Memory not allocated for newnode");
    }
    else
    {
        if(rear==NULL&&front==NULL)
        {
            rear=newnode;
            front=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
    }
}

void dequeue()
{
    if(rear==NULL&&front==NULL)
    {
        printf("EMPTY");
    }
    else if(front==rear)
    {
        current=front;
        printf("Deleted:%d",current->data);
        front=NULL;
        rear=NULL;
        free(current);
    }
    else
    {
        current=front;
        printf("Deleted:%d",current->data);
        front=front->next;
        free(current);
    }
}

void display()
{
    if(rear==NULL&&front==NULL)
    {
        printf("QUEUE EMPTY");
    }
    else
    {
        current=front;
        while(current!=NULL)
        {
            printf("%d\t",current->data);
            current=current->next;
        }
    }
}
void main()
{
    int ch;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:printf("Exiting...");
                break;
            default:printf("Invalid Choice");
        }
    }while(ch!=4);
}