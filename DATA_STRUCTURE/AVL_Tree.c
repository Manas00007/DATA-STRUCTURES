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

avl* get_height(avl* temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    return temp->height;
}


void update_height(avl* temp,int n)
{
    avl* temp2;
    if( temp->data==n)
    {
        return;
    }

    if(temp->data>n)
    {
        update_height(temp->left,n);
        temp->height=(get_height(temp->left)-get_height(temp->right))+1;
        check_fix_balance(temp,n);
        
    }
    else
    {
        update_height(temp->right,n);
        temp->height=(get_height(temp->left)-get_height(temp->right))+1;
    }

}  

void check_fix_balance(avl* temp,int n)
{
    int left_height=get_height(temp->left);
    int right_height=get_height(temp->right);
    int diff=left_height-right_height;

    if(diff>=2 || diff<=-2)
    {
        if(diff>=2)
        {
            // left left or left right rotation

        }
        else
        {
            // right right or right left rotation 
        }
    }

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
    new->right=NULL;
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
    }
    update_height(root,n);


}
int main()
{
    return 0;
}