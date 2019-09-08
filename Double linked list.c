#include <stdio.h>
#include <stdlib.h>
void insert_beg();
void insert_pos();
void insert_end();
void delete_beg();
void delete_end();
void delete_pos();
void display();
struct dll *start=NULL,*r,*p,*q,*temp;
int pos,val,i;
struct dll
{
    int data;
    struct dll *prev,*next;
};
int main()
{
    int ch;
    printf("============DOUBLY LINKED LIST MENU=============");
    while(1)
    {
        printf("\n1.Insertion at the beginning\n2.Insertion at the position\n3.Insertion at the end\n4.Deletion at the beginning\n5.Deletion at the position\n6.Deletion at the end\n7.Display\n8.Exit\n\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_beg();
                   break;
            case 2:insert_pos();
                   break;
            case 3:insert_end();
                   break;
            case 4:delete_beg();
                   break;
            case 5:delete_pos();
                   break;
            case 6:delete_end();
                   break;
            case 7:display();
                   break;
            case 8:exit(0);
            default:printf("!!!!Enter valid input!!!!");
        }
    }
    return 0;
}
void insert_beg()
{
    temp=(struct dll*)malloc(sizeof(struct dll));
    printf("Enter the data\n");
    scanf("%d",&val);
    temp->data=val;
    if(start==NULL)
    {
        temp->next=NULL;
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        temp->next=start;
        temp->prev=NULL;
        start->prev=temp;
        start=temp;
    }
    printf("%d element successfully inserted at the starting\n",val);
}
void insert_end()
{
    temp=(struct dll*)malloc(sizeof(struct dll));
    printf("Enter the data\n");
    scanf("%d",&val);
    temp->data=val;
    if(start==NULL)
    {
        temp->next=temp->prev=NULL;
        start=temp;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        temp->prev=p;
        p->next=temp;
        temp->next=NULL;
    }
    printf("%d element successfully inserted at the ending\n",val);
}
void insert_pos()
{
    if(start==NULL)
    {
        printf("!!DLL is empty\n");
        return;
    }
    p=start;
    temp=(struct dll*)malloc(sizeof(struct dll));
    printf("Enter the data\n");
    scanf("%d",&val);
    temp->data=val;
    printf("Enter the position to insert:\n");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++);
    {
        p=p->next;
    }
    q=p->next;
    temp->next=q;
    q->prev=temp;
    p->next=temp;
    temp->prev=p;
    printf("%d element successfully inserted at the %d position\n",val,pos);
}
void delete_beg()
{
    p=start;
    start=start->next;
    start->prev=NULL;
    free(p);
    printf("First element successfully deleted:");
}
void delete_end()
{
    p=start;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    q=p->next;
    p->next=NULL;
    free(q);
    printf("Last element successfully deleted:");
}
void delete_pos()
{
    p=start;
    printf("Enter the position to delete:\n");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    q=p->next;
    r=q->next;
    p->next=r;
    r->prev=p;
    free(q);
    printf("Element at %d position successfully deleted:",pos);
}
void display()
{
    p=start;
    printf("The elements in the doubly linked list are:\n");
    if(start==NULL)
    {
        printf("DLL is empty!!\n");
    }
    while(p->next!=NULL)
    {
        printf("%d ->",p->data);
        p=p->next;
    }
    printf("%d\n!!!End of double linked list!!!\n\n",p->data);
}
