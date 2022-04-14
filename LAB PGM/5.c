#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
#include <ctype.h>
int compute(int op1,int op2,char symbol);
int pop(int*top,int stack[]);
void push(int result,int*top,int stack[]);
int evalpostfix(char postfix[]);
void main()
{
    char postfix[SIZE];
    printf("enter the postfix expression\n");
    scanf("%s",postfix);
    int res;
    res=evalpostfix(postfix);
    printf("the evaluation of postfix expression is %d",res);
    
    
}
int evalpostfix(char postfix[])
{
    int token,op1,op2,stack[SIZE],i=0,top=-1,result;
    char symbol;
    while(postfix[i]!='\0')
    {
        symbol=postfix[i];
    
      if(isdigit(symbol))
      {
        token =symbol-'0';
          push(token,&top,stack);
      }
      else
      {
     op1=pop(&top,stack);
     op2=pop(&top,stack);
     result=compute(op1,op2,symbol);
     push(result,&top,stack);
      }
      i=i+1;
    }
    return(pop(&top,stack));
}  


void push(int result,int*top,int stack[])
{
    (*top)++;
    stack[*top]=result;
}
int pop(int*top,int stack[])
{
    int i=stack[*top];
    (*top)--;
    return i;
}
int compute(int op1,int op2,char symbol)
{
    switch(symbol)
    {
    case '+':return(op1+op2);
             break;
    case  '-':return(op1-op2);
            break;
    case '*':return(op1*op2);
            break;
    case'/':return(op1/op2);
            break;
    }        
}