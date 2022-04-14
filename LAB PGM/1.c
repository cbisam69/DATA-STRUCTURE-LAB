#include<stdio.h>
#include<stdlib.h>
#define s 100

void create(int arr[],int n);
void insert(int ele,int arr[],int pos,int*n);
void delete(int pos,int arr[],int*n);
void display(int arr[],int n);

void main()
{
    int arr[s],n,pos,ele;
    int ch;
    for(;;)
    {
        printf("enter 1 to create 2 to insert 3 to delete 4 to diplay 5 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create(arr,n);
                   break;
                   
            case 2: 
                    insert(ele,arr,pos,&n);
                   break;
            case 3:delete(pos,arr,&n);
                   break;
            case 4:display(arr,n);
                   break;
            case 5:exit(0);
        }    
    }    
}


void create(int arr[],int n)
{
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the elemnt\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

 }
void insert(int ele,int arr[],int pos,int*n)
{    
    printf("enter the elemnt to insert\n");
    scanf("%d",&ele);
    printf("enter the postion of insertion\n");
    scanf("%d",&pos);
    for(int i=(*n-1);i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=ele;
    *n=*n+1;
}
void delete(int pos,int arr[],int*n)
{   int i;
    printf("enter the positon to delete \n");
    scanf("%d",&pos);
    for(i=(pos-1);i<(*n-1);i++)
    {
        arr[i]=arr[i+1];
    }
    *n=*n-1;
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
     {
         printf("%d",arr[i]);
     }
}
