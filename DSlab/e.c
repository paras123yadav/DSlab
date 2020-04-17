#include<stdio.h>
#include<stdlib.h>
struct node 
{
    char data;
    struct node *left,*right;
}*root;

    struct node *Create(struct node *root, char item)
    {
        if(root == NULL)
        {
            root = (struct node *)malloc(sizeof(struct node));
            root->left = root->right = NULL;
            root->data = item;
            return root;
        }
        else
        {
            if(item < root->data )
                root->left = Create(root->left,item);
            else if(item > root->data )
                root->right = Create(root->right,item);
            else
                printf(" Duplicate Element !! Not Allowed !!!");

            return(root);
        }
    }
void preorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
    
}
void inorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    preorder(root->left);
    printf("%c",root->data);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
    
}
int main()
{
    int n,i;
    char item;
    root = NULL;
    printf("\nenter number of nodes you want: ");
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        printf("\nEnter data for node %d : ", i);
        fflush(stdin);
        scanf("%c",&item);
        root = Create(root,item);
    }

    printf("\npre-order is:");
    preorder(root);
    printf("\nin-order is:");
    inorder(root);
    printf("\npost-order is:");
    postorder(root);
}