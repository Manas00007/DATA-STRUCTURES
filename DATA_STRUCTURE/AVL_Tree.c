#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct node
{
    int data;
    int height;
    struct node* left;
    struct node* right;
}avl;


avl* root;


void create()
{

    int n;
    printf("Enter data:");
    scanf("%d",&n);

    avl* new=(avl*) malloc(sizeof(avl));

    new->data=n;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    root=new;
}

int get_height(avl* temp)
{
    if(temp==NULL)
    {
        return 0;
    }

    return temp->height;
}

avl* traverse(avl* temp,int n)
{
    if(temp=NULL)
    {
        return NULL;
    }
    if(temp->data==n)
    {
        printf("Already Exist!");
        return NULL;
    }

    if(temp->data>n)
    {
        if(temp->left==NULL)
        {
            return temp;
        }
        else
        {
            return traverse(temp->left,n);
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
            return traverse(temp->right,n);
        }
    }
}


int balance_factor(avl* temp)
{
    return (get_height(temp->left)-get_height(temp->right));
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

int update_height(avl* temp)
{
    return max(get_height(temp->left),get_height(temp->right))+1;
}

void insert()
{
    if(root==NULL)
    {
        create();
        return;
    }

    avl* new=(avl*) malloc(sizeof(avl));
    int n;
    printf("\n Enter data: ");
    scanf("%d",&n);
    new->data=n;
    new->height=1;
    new->left=NULL;
    new->right=NULL;

    avl* temp=traverse(root,n);
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
     root->height=update_height(root);

        int bf=balance_factor(root);

        if(bf>1 && root->left->data>n)
        {
            //LL rotation
        }
        if(bf<-1 && root->right->data<n)
        {
            //RR rotation
        }
        if(bf>1 && root->left->data<n)
        {
            //LR rotation
        }
         if(bf<-1 && root->right->data>n)
        {
            //RL rotation
        }

}

int main()
{
    return 0;
}