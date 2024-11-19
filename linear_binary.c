#include <stdio.h>
void  linear1(int a[],int n, int key);
void  binary1(int a[],int n, int key);
void main()
{
int a[20],ch,n,key;
printf("enter the size of array");
scanf("%d",&n);
printf("enter the array elements");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the element to be found");
scanf("%d",&key);
while(ch!=3)
{
printf("\n1.Linear Search\n2.Binary Search\n3.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: linear1(a,n,key);
	break;
case 2: binary1(a,n,key);
	break;
case 3:printf("exiting");
	break;
default : printf("wrong choice");
}
}
}
void linear1(int a[],int n, int key)
{
int i,flag=0;
for (int i=0;i<n;i++)
{
if(a[i]==key)
{
flag=1;
printf("element found at %d",i+1);
break;
}
}
if (flag==0)
{
printf("element not found");
}

//return(0);
}
			
void binary1(int a[],int n,int key)
{
int beg=0,end=0,mid=0,temp;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-1-i;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}

while(beg<=end)
{
mid=(beg+end)/2;
end=n-1;
beg=0;
if(a[mid]==key)
{
printf("key found");
break;
}
else if(key>a[mid])
{
beg=mid+1;
}
else
{
end=mid-1;
}
}
if(beg>end)
{
printf("element not fond");
}
}
//return(0);


	

