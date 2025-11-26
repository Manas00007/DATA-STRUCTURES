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


void LL(avl* temp)
{

    avl* parnt=parent(temp);
    avl* temp2=temp->left;
    parnt->left=temp2;
    if(temp->right!=NULL)
    {
        temp2->right=temp;
    }
    else
    {
        
        avl* child=temp2->right;
        temp2->right=temp;
        temp->left=child;
       
    }

}

void RR(avl* temp)
{
      avl* parnt=parent(temp);
      avl* temp2=temp->right;
      parnt->right=temp2;
      if(temp2->left!=NULL)
      {
        temp2->left=temp;
      }
      else
      {
        avl* child=temp2->left;
        temp2->left=temp;
        temp->right=child;
      }

}

avl* parent(int n,avl* temp)
{
    if(temp->data==n)
    {
        return temp;
    }

    if(temp->data>n)
    {
        parent(n,temp->left);
    }
    else
    {
        parent(n,temp->right);
    }
}
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
void rotate(avl* temp,int z)
{
    if(z>0)
    {
        LL(temp);
    }
    else
    {
        RR(temp)
    }
}

void check_balance(avl* temp)
 {
    if(temp==NULL)
    {
        return;
    }

    check_balance(temp->left);
    int x=temp->left->height;
    int y=temp->right->height;
    int z=x-y;
    if(z>=2 || z<=-2)
    {
        rotate(temp,z);
    }
    check_balance(temp->right);
    if(z>=2 || z<=-2)
    {
        rotate(temp,z);
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