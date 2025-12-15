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


avl* root=NULL;


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


avl* right_rotation(avl* parent)
{
   
    avl* child=parent->left;
    avl* temp=child->right;

    child->right=parent;
    parent->left=temp;
    

    parent->height=update_height(parent);
    child->height=update_height(child);
    return child;
}


avl* left_rotation(avl* parent)
{
    avl* child=parent->right;
    avl* temp=child->left;

    child->left=parent;
    parent->right=temp;

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

            temp=right_rotation(temp);
            return temp;
             //LL rotation
        }
         else if(bf>1 && balance_factor(temp->left)<0)
        {
            temp->left=left_rotation(temp->left);
            temp=right_rotation(temp);
            return temp;

            //LR rotation
        }
        else if(bf<-1 && balance_factor(temp->right)<=0)
        {
            temp=left_rotation(temp);
            return temp;    
            //RR rotation
        }
       
         else if(bf<-1 && balance_factor(temp->right)>0)
        {
           
            temp->right=right_rotation(temp->right);
            temp=left_rotation(temp);
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


avl* search(avl* temp,int n)
{
    if(temp==NULL)
    {
        printf("\n Data not found");
        return NULL;
    }
    // if(temp->data==n)
    // {
    //     printf("Already Exist!");
    //     return NULL;
    // }

    if(temp->data>n)
    {
        if(temp->left->data==n || temp->right->data==n)
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
          if(temp->right->data==n || temp->left->data==n)
        {
            return temp;
        }
        else
        {
            return traverse(temp->right,n);
        }
    }
}
void delete()
{
    if(root==NULL)
    {
        printf("\nNo element found..\n");
        return;
    }
    
    printf("Enter element to delete");
    int n;
    scanf("%d",&n);
    avl* temp=root;
    if(root->left==NULL && root->right==NULL && root->data==n)
    {
        root=NULL;
        free(temp);
        return;
    }

    avl* data_parent=search(root,n);
    avl* data_node

    if(data_parent->data>n)
    {
    data_node=data_parent->left;
    }
    else
    {
      data_node=data_parent->right;
    }

    if()
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