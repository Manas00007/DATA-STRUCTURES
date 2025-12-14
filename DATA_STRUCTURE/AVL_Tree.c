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
    if(temp==NULL)
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


avl* right_rotation(avl* parent,avl* child)
{
    if(child->right!=NULL)
    {
        avl* temp=child->right;
        parent->left=temp;
        temp->height=update_height(temp);
    }
    child->right=parent;
    parent->height=update_height(parent);
    child->height=update_height(child);
    return child;
}


avl* left_rotation(avl* parent,avl* child)
{
    if(child->left!=NULL)
    {
        avl* temp=child->left;
        parent->right=temp;
        temp->height=update_height(temp);
    }

    child->left=parent;
    parent->height=update_height(parent);
    child->height=update_height(child);
    return child;
}

avl* balance_tree(int n,avl* temp)
{
    if(temp==NULL)
    {
        return NULL;
    }

    if(temp->data==n)
    {
        return temp;
    }
    
    if(temp->data>n)
    {
        temp->left=balance_tree(n,temp->left);
    }
    else
    {
        temp->right=balance_tree(n,temp->right);
    }
    temp->height=update_height(temp);

    int bf=balance_factor(temp);


    if(bf>1 && balance_factor(temp->left)>=0)
        {
            avl* child=temp->left;
            avl* parent=temp;
            temp=right_rotation(parent,child);
            return temp;
             //LL rotation
        }
         else if(bf>1 && balance_factor(temp->left)<0)
        {
            avl* parent=temp;
            avl* child=temp->left;
            avl* grandchild=child->right;

            child=left_rotation(child,grandchild);
            temp=right_rotation(parent,child);
            return temp;

            //LR rotation
        }
        else if(bf<-1 && balance_factor(temp->right)<=0)
        {
            avl* child=temp->right;
            avl* parent=temp;
           
            temp=left_rotation(parent,child);
            return temp;    
            //RR rotation
        }
       
         else if(bf<-1 && balance_factor(temp->right)>0)
        {
            avl* parent=temp;
            avl* child=temp->right;
            avl* grandchild=child->left;
            child=right_rotation(child,grandchild);
            temp=left_rotation(parent,child);
            return temp;

            //RL rotation
        }
        else
        {
            return temp;
        }

        return temp;

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
    printf("Enter data: ");
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
     root=balance_tree(n,root);


}


void preorder(avl* temp)
{
    if(temp==NULL)
    {
        return;
    }

    printf(" %d",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void inorder(avl* temp)
{
    if(temp==NULL)
    {
        return;
    }
    inorder(temp->left);
    printf(" %d",temp->data);
    inorder(temp->right);
}

void postorder(avl* temp)
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
insert();
insert();
// insert();
// insert();
display();
return 0;

}