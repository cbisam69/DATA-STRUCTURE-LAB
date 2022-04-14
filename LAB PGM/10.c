#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node*rlink,*llink;
}NODE;
NODE*insert(int ele,NODE*root);
int search(int key,NODE*root);
void inorder(NODE*root);
void preorder(NODE*root);
void postorder(NODE*root);
NODE*get_node();

int main()
{
    NODE*root=NULL;
    int ch, ele,key;
    for(;;)
    {
        printf("Enter 1 to insert 2 to preorder 3 to postorder 4 to inorder 5 to search\n");
        scanf("%d",&ch);
        switch (ch)
        {
         case 1:printf("enter teh elemnt to insert\n");
         scanf("%d",&ele);
         root=insert(ele,root);
         break;
         case 2:preorder(root);
         break;
         case 3:postorder(root);
         break;
         case 4:inorder(root);
         break;
         case 5:search(key,root);
        }
    }
}
int search(int key,NODE*root)
{
    while(root!=NULL)
    {
        if(root->data==key)
        return key;
        else if(root->data<key)
        search(key,root->rlink);
        else
        search(key,root->llink);

    }
   return -1; 
}

void inorder(NODE*root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\n",root->data);
        inorder(root->rlink);
    }
}
void preorder(NODE*root)
{
    if(root!=NULL)
    {   
        printf("%d\n",root->data);
        inorder(root->llink);
        inorder(root->rlink);
    }
}

void postorder(NODE*root)
{
    if(root!=NULL)
    {   
        inorder(root->llink);
        inorder(root->rlink);
        printf("%d\n",root->data);
    }
}

NODE*insert(int ele,NODE*root)
{
    NODE*new=get_node();
    NODE*previous,*preseent;
    new->data=ele;
    new->rlink=new->llink=NULL;
    if(root==NULL)
    {
        return new;
    }
     if(root->data>ele)
    {
     root->llink=insert(ele,root->llink);
    }
    else if(root->data<ele)
    {
        root->rlink=insert(ele,root->rlink);
    }
    
    else
    {
        return(insert(ele,root->rlink));
    }
    return root;
}


NODE*get_node()
{
    NODE*ptr;
    ptr=(NODE*)malloc(sizeof(NODE));\
    if(ptr==NULL)
    {
        printf("NO memory\n");
        return NULL;
    }
    return ptr;
}