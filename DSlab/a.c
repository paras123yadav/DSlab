#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
}*head;

void traverse()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->link;
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
    if(head->link==NULL)
    {
        printf("only one node is present");
        free(head);
        head=NULL;
    }
    head=head->link;
    free(temp);

    
}
void del_at_end()
{
    struct node *temp;
    temp=head;
    while(temp->link->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=NULL;
    free(temp->link);
    
}
void del_in_bet()
{
    struct node *temp,*temp1;
    temp=head;
    while(temp->link->data!=3)
    {
        temp=temp->link;
    }
      temp1=temp->link;
      temp->link=temp1->link;
      free(temp1);
}


int main()
{
    int data;
    struct node *temp,*temp1;
    int n,x;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("\nmemory not allocated");
    }
    else
    {
        printf("enter head data=");
        scanf("%d",&x);
        head->data=x;
        temp=head;
    }
    printf("\nenter number of nodes you want to make other than head node");
    scanf("%d",&n);
    printf("head data=10\n");
    for(int i=0;i<n-1;i++)
    {
        temp1=(struct node*)malloc(sizeof(struct node));
        if(temp1==NULL)
        {
            printf("\nmemory not allocated");
        }
        printf("enter data = %n ");
        scanf("%d",&data);
        temp1->data=data;
        temp1->link=NULL;
        temp->link=temp1;
        temp=temp->link;
    
    }
    del_at_beg();
    traverse();
    del_at_end();
    traverse();
    del_in_bet();
    traverse();
}