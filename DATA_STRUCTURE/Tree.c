#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}tree;

tree* root=NULL;

void create()
{
    int n;
    printf("Enter data: ");
    scanf("%d",&n);

    root=(tree*) malloc(sizeof(tree));

    root->data=n;
    root->left=NULL;
    root->right=NULL;
}

tree* traverse(int n ,tree* temp){
    

    if(temp==NULL)
    {
        return NULL;
    }
    if(temp->data==n)
    {
        printf("already found");
        return temp;
    }
    
        if(temp->data>n)
        {
            if(temp->left==NULL)
            {
                return temp;
            }
            else
            {
            return traverse(n,temp->left);
            }
           
        }
        else
        {
            if(temp->right==NULL)
            {
                return temp;
            }
            else
            {
            return traverse(n,temp->right);
            }
        }

    
}


void insertion()
{
    if(root==NULL)
    {
        create();
        return;
    }
    int n;
    printf("Enter data: ");
    scanf("%d",&n);

    tree* new=(tree*) malloc(sizeof(tree));

    tree* parent=traverse(n,root);
    if(parent==NULL)
    {
        return;
    }


    new->data=n;
    new->left=NULL;
    new->right=NULL;

    if(parent->data>n)
    {
        parent->left=new;
    }
    else
    {
        parent->right=new;
    }

}


void preorder(tree* temp)
{

    if(temp==NULL)
    {
        return;
    }
    printf(" %d",temp->data);
    preorder(temp->left);
    preorder(temp->right);

}

void inorder(tree* temp)
{
    if(temp==NULL)
    {
        return;
    }

    inorder(temp->left);
    printf(" %d",temp->data);
    inorder(temp->right);
}

void postorder(tree* temp)
{
    if(temp==NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf(" %d",temp->data);
}

void display()
{
    if(root==NULL)
    {
        printf("NO element found");
        return;
    }
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
}
int main()
{

    create();
    insertion();
    insertion();

    insertion();

    insertion();
    insertion();

    display();
    return 0;
}