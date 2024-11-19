#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top=NULL,*current,*newnode;
void push()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(top==NULL)
    {
        top=newnode;
        top->next=NULL;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("UNDERFLOW");
    }
    else
    {
        current=top;
        top=top->next;
        printf("Deleted:%d",current->data);
        free(current);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("STACK EMPTY");
    }
    else
    {
        current=top;
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
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:printf("Exiting...");
                break;
            default:printf("Invalid choice");
        }
    }while(ch!=4);
}