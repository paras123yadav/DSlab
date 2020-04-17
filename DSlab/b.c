#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node *p;
     struct node *n;
}*head;

void traverse()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->n;
    }
}

void del_at_beg()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("no node to delete");
    }
    if(head->n==NULL)
    {
        printf("one node is present");
        head=NULL;
        free(head);
    }
    head=head->n;
    head->p=NULL;
    free(temp);
}

void del_at_end()
{
    struct node *temp;
    temp=head;
    while(temp->n!=NULL)
    {
        temp=temp->n;
    }
    temp->p->n=NULL;
    free(temp);
}
void del_in_bet()
{
    int count;
    printf("enter the position of node you want to delete=");
    scanf("%d",&count);
    struct node *temp,*temp1;
    temp=head;
    for(int i=2;i<count;i++)
    {
        temp=temp->n;
    }
    temp1=temp->n;
    temp->n=temp1->n;
    temp1->n->p=temp;
    free(temp1);
}

int main()
{
    int n,x;
    int data;
    struct node *temp,*temp1;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("memory not allocated");
    }
    printf("enter head data");
    scanf("%d",&x);
    head->data=x;
    head->n=NULL;
    head->p=NULL;
    temp=head;
    printf("\nenter number of nodes you want to make including head node");
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        temp1=(struct node*)malloc(sizeof(struct node));
        printf("enter data = %n");
        scanf("%d",&data);
        temp1->data=data;
        temp1->p=temp;
        temp->n=temp1;
        temp1->n=NULL;
        temp=temp->n;
    }
    del_at_beg();
    traverse();
    del_at_end();
    traverse();
    del_in_bet();
    traverse();
}