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

int maximum(avl* left,avl* right)
{
    if(left==NULL && right==NULL)
    {
        return -1;
    }
    else if(left!==NULL && right==NULL)
    {
        return left->height;
    }
    else if(left==NULL && right!=NULL)
    {
        return right->height;
    }
    else
    {
        if(left->height>right->height)
        {
            return left->height;

        }
        else
        {
            return right->height;
        }
    }
}


void update_height(avl* temp)//update the height of tree
{

    if(temp==NULL)
    {
        return;
    }

    update_height(temp->left);
    update_height(temp->right);
    temp->height=1+maximum(temp->left,temp->right);
    return;

}

//this function check balance of tree and if it is unbalance it balance the tree
void check_fix_balance(avl* temp,int n)   //temp = root refrenece
{

    if(temp->data==n)
    {
        return;
    }

    if(temp->data>n)
    {
        check_fix_balance(temp->left,n);
    }
    else
    {
        check_fix_balance(temp->right,n)
    }

    int x=temp->left->height;
    int y=temp->right->height;
    int z=x-y;
    if(z>=2 || z<=-2)
    {
        avl* parent = rotate(temp,z); // this function rotate and return new parent node for height updation....
        update_height(parent);
    }
    return;
}

avl* rotate(avl* temp, int n);
{
    if(n>-1)
    {
        // left subtree
    }
    else
    {
        //right subtree 
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
    }
    update_height(root);

    check_fix_balance(root,n)


}
int main()
{
    return 0;
}