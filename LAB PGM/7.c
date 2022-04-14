#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int sem;
    char name[10];
    char usn[10];
    long int phno;
    struct node *link;
} NODE;

typedef struct head
{
    int count;
    struct node *link;
} HEAD;
void display(HEAD*head);
void del_rear(HEAD *head);
void del_front(HEAD *head);
void ins_rear(HEAD *head);
void ins_front(HEAD *head);
void main()
{
    HEAD *head = (HEAD *)malloc(sizeof(HEAD));
    head->count = 0;
    head->link = NULL;
    int ch;
    for (;;)
    {   
        printf("1 to insert front 2 to insert rear 3 to delete front 4 to delete rear 5 to display 6 to terminate\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            ins_front(head);
            break;
        case 2:
            ins_rear(head);
            break;
        case 3:
            del_front(head);
            break;
        case 4:
            del_rear(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        }
    }
}

void ins_front(HEAD *head)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    printf("enter students details\n");
    scanf("%d%s%s%ld", &new->sem, new->name, new->usn, &new->phno);
    new->link = head->link;
    head->link = new;
    (head->count)++;
}
void ins_rear(HEAD *head)
{
    NODE *temp;
    NODE *new = (NODE *)malloc(sizeof(NODE));
    printf("enter students details\n");
    scanf("%d%s%s%ld", &new->sem, new->name, new->usn, &new->phno);
    new->link = NULL;
    if (head->link == NULL) // for zero
    {
        head->link = new;
        (head->count)++;
    }
    else
    {
        temp = head->link;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
        (head->count)++;
    }
}

void del_front(HEAD *head)
{
    NODE *temp;
    if (head->link == NULL)
    {
        printf("list empty\n");
    }

    temp = head->link;
    printf("The deleted record is \n");
    printf("%d%s%s%ld", temp->sem, temp->name, temp->usn, temp->phno);
    head->link = temp->link;
    (head->count)--;
    free(temp);
}
void del_rear(HEAD *head)
{
    NODE *prev, *present;
    if (head->link == NULL)
    {
        printf("list empty\n");
    }
    present = head->link;
    if (present->link == NULL)
    {
        printf("list contais only one record\n");

        head->link = NULL;
    }
    else
    {
        while (present-> link != NULL)
        {
            prev = present;
            present = present->link;
        }
        prev->link = NULL;
    }
    printf("THE deleted data is \n");
    printf("%d%s%s%ld", present->sem, present->name, present->usn, present->phno);
    (head->count)--;
    free(present);
}

void display(HEAD*head)
{
    NODE*temp;
     if (head->link == NULL)
    {
        printf("list empty\n");
    }
    temp=head->link;
    while (temp!=NULL)
    {
    printf("the details are\n");
    printf("%d\t%s\t%s\t%ld\n", temp->sem, temp->name, temp->usn, temp->phno);
    temp=temp->link;
    }

    
}
