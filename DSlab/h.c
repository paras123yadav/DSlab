#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;
void preorder(struct node *root)
{
    if (root==0)
    {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
    
}
void inorder(struct node *root)
{
    if (root==NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root==0)
    {
        return;
    }
    else
    {   
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
int height(struct node *root)
{
    int l,r;
    if (root==NULL)
    {
        return 0;
    }
    else if (root->left==NULL&&root->right==NULL)
    {
        return 0;
    }
    else
    {
        l=height(root->left);
        r=height(root->right);
        return 1+(l>r?l:r);
    }
}
void main()
{
    int i,data,n;
    struct node *temp,*temp1;
    printf("enter number of nodes you want");
    scanf("%d",&n);
    for ( i = 0; i <n ; i++)
    {
        temp1=(struct node *)malloc(sizeof(struct node));
        printf("enter the data for node");
        scanf("%d",&data);
        temp1->data=data;
        temp1->left=NULL;
        temp1->right=NULL;
        if (i==0)
        {
            root=temp1;
        }
        else
        {
            temp=root;
            while(1)
            {
                if (temp1->data>temp->data)
                {
                    if (temp->right==NULL)
                    {
                        temp->right=temp1;
                        break;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
                else
                {
                    if (temp->left==NULL)
                    {
                        temp->left=temp1;
                        break;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
            }
        }
    }
    printf("\nthe preorder traversal of the tree :");
    preorder(root);
    printf("\nthe inorder traversal of this tree :");
    inorder(root);
    printf("\nthe postorder traversal of the tree :");
    postorder(root);
    printf("height of the tree is:%d",height(root));

}