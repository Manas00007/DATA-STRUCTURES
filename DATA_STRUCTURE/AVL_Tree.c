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
        check_fix_balance(temp,n);

    }

}  


avl* superParent(int n,avl* temp)
{
    if(temp==NULL)
    {
        return NULL;
    }


    if(temp->data>n)
    {
        if(temp->left->data==n)
        {
            return temp;
        }
        else
        {
        return superParent(n,temp->left);
        }
    }
    else
    {
         if(temp->right->data==n)
        {
            return temp;
        }
        else
        {
        return superParent(n,temp->right);
        }
    }

}   

void LL(avl* parent)
{
    avl* grand=superParent(parent->data,root);
    avl* child=temp->left;

    grand->left=child;

    if(child->right!=NULL)
    {
        avl* temp=child->right;
        parent->left=temp;
    }
    child->right=parent;

    update_height(root,child->data);

}

void LR(avl* parent)
{

    avl* child=parent->left;
    avl* temp=child->right;

    parent->left=temp;
    temp->left=child;

    LL(parent);



}


void RR(avl* parent)
{
    avl* grand=superParent(parent->data,root);
    avl* child=parent->right;

    grand->right=child;

    if(child->left!=NULL)
    {
        avl* temp=child->left;
        parent->right=temp;
    }

    child->left=parent;

}


void RL(avl* parent)
{

    avl* child=parent->right;
    avl* temp=child->left;
    parent->right=temp;
    temp->right=child;

    RR(parent);

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
            avl* child=temp->left;
            if(child->left==NULL)
            {
                LR(temp);
            }
            else
            {
                LL(temp);
            }

            // left left or left right rotation

        }
        else
        {
            avl* child=temp->left;
            if(child->right==NULL)
            {
                RL(temp);
            }
            else
            {
                RR(temp);
            }
            // right right or right left rotation 
        }
    }

}


avl* traverse(int n, avl* temp)
{

    if(temp==NULL)
    {
        return NULL;
    }

    if(temp->data==n)
    {
        printf("Already exist!");
        return NULL;

    }




    if(temp->data>n)
    {

        if(temp->left==NULL)
        {
            return temp;
        }
        else{

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