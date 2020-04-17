#include<stdio.h>
#define Max 5
int dque[Max];
int front=-1;
int rear=-1;
void enquefront()
{
    int x;
    printf("enter data you want to enque at front=");
    scanf("%d",&x);
    if ((front==0&&rear==Max-1)||front==rear+1)
    {
        printf("Overflow!!\n");
    }
    else if (front==-1&&rear==-1)
    {
        front=rear=0;
        dque[front]=x;
    }
    else if (front==0)
    {
        front=Max-1;
        dque[front]=x;
    }
    else
    {
        front--;
        dque[front]=x;
    } 
}
void enquerear()
{
    int x;
    printf("enter data you want to enque at rear=");
    scanf("%d",&x);
    if ((front==0&&rear==Max-1)||front==rear+1)
    {
        printf("Overflow!!\n");
    }
    else if (front==-1&&rear==-1)
    {
        front=rear=0;
        dque[rear]=x;
    }
    else if (rear=Max-1)
    {
        rear=0;
        dque[rear]=x;
    }
    else
    {
        rear++;
        dque[rear]=x;
    }
}
void dequefront()
{
    if (front==-1&&rear==-1)
    {
        printf("Underflow!!\n");
    }
    else if (front==rear)
    {
        front=rear=-1;
    }
    else if (front==Max-1)
    {
        printf("dequed element is %d\n",dque[front]);
        front=0;
    }
    else
    {
        printf("dequed element is %d\n",dque[front]);
        front++;
    }    
}
void dequerear()
{
    if (front==-1&&rear==-1)
    {
        printf("Underflow!!\n");
    }
    else if (front==rear)
    {
        front=rear=-1;
    }
    else if (rear==0)
    {
        printf("dequed element is %d\n",dque[rear]);
        rear=Max-1;
    }
    else
    {
        printf("dequed element is %d\n",dque[rear]);
        rear--;
    }
}
void display()
{
    int i;
    if (front==-1&&rear==-1)
    {
        printf("nothing to display\n");
    }
    else
    {
        printf("queue:");
        for ( i = front; i <=rear+1; i=(i+1)%Max)
        {
            printf("%d ",dque[i]);
        }   
    }
}
int main()
{
    int choice;
    printf("\npress 1 to enquefront an element");
    printf("\npress 2 to enquerear an element");
    printf("\npress 3 to dequefront an element");
    printf("\npress 4 to dequerear an element");
    printf("\npress 5 to display");
    printf("\npress 6 to end\n");
    while(1)
    {
        printf("enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enquefront();
            break;
        case 2:
            enquerear();
            break;
        case 3:
            dequefront();
            break;
        case 4:
            dequerear();
            break;
        case 5:
            display();
            break;
        case 6:
            end(0);
            break;                
        default:
            printf("wrong key pressed!!!");
            break;
        }
    }
}