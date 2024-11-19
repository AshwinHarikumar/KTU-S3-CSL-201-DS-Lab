#include<stdio.h>
int stack[10],top=-1,n;
void push();
void pop();
void display();
void main()
{
int ch;
printf("Enter the maximum size of stack");
scanf("%d",&n);
while(ch!=4)
{
printf("\nenter the choice");
printf("\n1.push,\n2.pop,\n3.display,\n4.exit\n");
scanf("%d",&ch);
switch(ch)
{
	case 1:
		push();
		break;
	case 2:
		pop();
		break;
	case 3: 
		display();
		break;
	case 4:
		printf("Exiting");
		break;	
	default : 
		
		printf("Wrong choice");
}
}
}		

void push()
{
int item;
printf("enter the element");
scanf("%d",&item);
if(top>=n-1)
{
printf("stack overflow");
}
else
{
top=top+1;
stack[top]=item;
}
}
void pop()
{
int item;
if (top==-1)
{
printf("stack underflow");

}
else
{
item=stack[top];
printf("deleted item %d",item);
top=top-1;
}
}
void display()
{
if(top==-1)
{
printf("empty stack");
}
else
{
for(int i=0;i<=top;i++)
{
printf("%d\t",stack[i]);
}
printf("\n");
}

}
 

			
