//stack implementation using array static
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
void display(int top, int stack[]);
void push(int ele,int*top,int stack[]);
 int pop(int*top,int stack[]);

void main()
{
    int stack[SIZE], ele, del_ele, top = -1, n;
    int ch;

    printf("enter the size of stack\n");
    scanf("%d", &n);

    for (;;)
    {
        printf("ENTER 1 to push\n 2 to pop\n 3 to display\n 4 to exit\n ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (top == (n - 1))
            {
                printf("stack is full\n");
                break;
            }
            printf("enter the element to push\n");
            scanf("%d", &ele);
            push(ele, &top, stack);
            break;
        case 2:
            if (top == -1)
            {
                printf("stack is empty\n");
                break;
            }

            del_ele = pop(&top, stack);
            printf("the deleted elemnt is %d", del_ele);
            break;
        case 3:
            printf("the content of stack is \n");
            display(top, stack);
            break;
        case 4:
            exit(0);
        }
    }
}

void push(int ele,int*top,int stack[])
{
    (*top)++;
    stack[(*top)]=ele;

}

 int pop(int*top,int stack[])
{
    int i;
    i=stack[(*top)];
    (*top)--;
    return i;
}

void display(int top, int stack[])
{
    for(int i=top;i>=0;i--)
    {
        printf("%d",stack[i]);
    }
}
