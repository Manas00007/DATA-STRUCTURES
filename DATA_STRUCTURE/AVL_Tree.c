#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node{
    int data;
    int height;
    struct node* left;
    struct node* right;
}avl;


avl* root=NULL;


avl* traverse(int n,avl* temp)
{


    if(temp->right==NULL|| temp->left==NULL)
    {
        return temp;
    }
    if(temp->data==n){
        printf("\nPlase don't enter duplicate data \n");
        return NULL;
    }
    if((temp->left!=NULL && temp->left==n)||(temp->right!=NULL && temp->left==n))
    {
        return NULL;
    }

    if(temp->data>n)
    {
        traverse(n,temp->left);
    }
    else
    {
        traverse(n,temp->right);
    }


}

void check_balance(avl* temp)
 {
    if(temp==NULL)
    {
        return;
    }

    check_balance(temp->left);
    check_balance(temp->right);

 }

void insert()
{

    int n;
    printf("Enter data: ");
    scanf("%d",&n);

    avl* temp=traverse(n,root);

    avl* new=(avl*) malloc(sizeof(avl));

    new->data=n;
    new->left=NULL;
    new->right==NULL;
    new->height=0;

    if(root==NULL)
    {
        root=new;
    }

    if(temp!=NULL)
    {
        if(temp->data>n)
        {
            temp->left=new;
        }
        else
        {
            temp->right=new;
        }


        check_balance(root);
    }


}
int main()
{
    return 0;
}