#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void insert(int ele,int*r,int queue[],int*count);
int delete(int*f,int queue[],int*count);
void display(int f,int queue[],int count);
int main()
{
   int queue[SIZE],n,ele,count,del_ele,ch;
   int r=-1,f=0;
   printf("enter the size of queue\n");
   scanf("%d",&n);
   for(;;)
   {
       printf("1 to insert 2 to delete 3 to display 4 to exit\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:if(count==(n-1))
           {
                  printf("queue is empty\n");
                  break;
           } 
           
           printf("enter the element to insert\n");
           scanf("%d",&ele);
           insert(ele,&r,queue,&count);
           break;
           case 2:if(count==0)
                  {
                      printf("queue is empty\n");
                      break;
                  }
                  del_ele=delete(&f,queue,&count);
                  printf("the deleted elemnt id %d",del_ele);
                  break;
            case 3:if(count==0)
                  {
                      printf("queue is empty\n");
                      break;
                  }
                  display(f,queue,count);
                  break;
            case 4:exit(0);          
       }
   }
}

void insert(int ele,int*r,int queue[],int*count)
{
    *r=(*r+1)%SIZE;
    queue[(*r)]=ele;
    *count=*count+1;
}
int delete(int*f,int queue[],int*count)
{
    int i=queue[(*f)];
    *f=(*f+1)%SIZE;
    *count=*count-1;
    return i;
}
void display(int f,int queue[],int count)
{
    for(int i=0;i<=count;i++)
    {
    printf("%d",queue[f]);
    f=(f+1)%SIZE;
    }
}