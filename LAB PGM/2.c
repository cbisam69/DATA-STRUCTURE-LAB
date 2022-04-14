#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display(char new_str[],int m,int n);
void pattern_match(char str[],char pat[],char rep_pat[],char new_str[],int*m,int*n);
void main(){
char str[100],pat[20],rep_pat[20],new_str[100];
int m=0,n=0;
printf("enter the string\n");
scanf("%s",str);
printf("enter the pattern\n");
scanf("%s",pat);
printf("enter the rep_pat\n");
scanf("%s",rep_pat);
pattern_match(str,pat,rep_pat,new_str,&m,&n);
display(new_str,m,n);
}

void pattern_match(char str[],char pat[],char rep_pat[],char new_str[],int*m,int*n)
{
    int i=0,j=0,flag=0;
    int k,rep_index;
    while(str[i]!='\0')
    {
        j=0,k=i,rep_index=0;
        while(str[k]==pat[j]&&pat[j]!='\0')
        {
            k++;
            j++;
        }
        if(pat[j]=='\0')
        {
            flag=1;
            *m=1;
            while(rep_pat[rep_index]!='\0')
            {
                new_str[(*n)]=rep_pat[rep_index];
                rep_index++;
                (*n)++;
            }
        }
        else{
            flag=0;
        }
        if(flag==1)
        {
         i=k;
        }
        else
        {
            new_str[(*n)]=str[i];
            i++;
            (*n)++;
        }
    }
}

void display(char new_str[],int m,int n)
{
    if(m!=1)
    {
        printf("pattern not found\n");
        exit(0);
    }
    new_str[n]='\0';
    printf("new string is\n");
    printf("%s",new_str);
}