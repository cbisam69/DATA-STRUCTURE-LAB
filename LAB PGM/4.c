#include<stdio.h>
#include<stdlib.h>
#define size 20
typedef enum {lparen,rparen,plus,minus,mul,divi,mod,power,eos,operand} precedence;
void infix_to_postfix(char infix[]);
void push(precedence token,int *top,int stack[]);
precedence pop(int *top,int stack[]);
void print_token(precedence token);
precedence get_token(char *symbol,int *n,char infix[]);

int main()
{
	char infix[size];

	printf("enter infix expression\n");
	scanf("%s",infix);

	printf("the postfix expression is \n");
	infix_to_postfix(infix);
    printf("\n");
	return 0;
}

void infix_to_postfix(char infix[])
{
	int isp[] = {0,4,1,1,2,2,2,3,0};
	int icp[] = {20,4,1,1,2,2,2,3,0};
	int stack[size],top =0,n=0;
	stack[top] = eos;
	char symbol;
	precedence token;
	for(token = get_token(&symbol,&n,infix);token != eos; token = get_token(&symbol,&n,infix))
	{
		if(token == operand)
			printf("%c",symbol);
		else if(token == rparen)
		{
			while(stack[top]!=lparen)
			{
				print_token(pop(&top,stack));
			}
			pop(&top,stack);
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
				{
					print_token(pop(&top,stack));
				}
				push(token,&top,stack);
		}

	}
	while((token = pop(&top,stack))!= eos)
		{
			print_token(token);
		}
}

precedence get_token(char *symbol,int *n,char infix[])
{
	*symbol = infix[(*n)++];
	switch(*symbol)
	{
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return plus;
		case '-' : return minus;
		case '*' : return mul;
		case '/' : return divi;
		case '%' : return mod;
		case '^' : return power;
		case '\0': return eos;
		default : return operand;
	}
}

void push(precedence token,int *top,int stack[])
{
	stack[++(*top)] = token;
}

precedence pop(int *top,int stack[])
{
	return stack[(*top)--];
}

void print_token(precedence token)
{
	switch(token)
	{
		case plus : 
		printf("+");
		break;
		case minus : 
		printf("-");
		break;
		case mul : 
		printf("*");
		break;
		case divi : 
		printf("/");
		break;
		case mod :
		printf("%%");
		break;
		case power :
		printf("^");
		break;
	}
}
//TOH
#include<stdio.h>
void TOH(int n,char A,char B,char C);
void main()
{
    int n,A,B,C;
    printf("enter the no.of plates\n");
    scanf("%d",&n);
    TOH(n,'A','B','C');
}
void TOH(int n,char A,char B,char C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("\n%c to%c",A,B);
        TOH(n-1,C,B,A);
    }
}