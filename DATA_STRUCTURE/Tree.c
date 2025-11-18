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
        printf("already exsists\n");
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


    tree* parent=traverse(n,root);
    if(parent==NULL)
    {
        return;
    }
    tree* new=(tree*) malloc(sizeof(tree));



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


    tree* find_node(int n,tree* temp)
    {
        if(temp==NULL)
        {
            return NULL;
        }

        if((temp->left !=NULL && temp->left->data==n)|| (temp->right !=NULL &&temp->right->data==n))
        {
            return temp;
        }

        if(temp->data>n)
        {
            if(temp->left==NULL)
            {
                return NULL;
            }
            else
            {
                return find_node(n,temp->left);
            }
        }
        else
        {
            if(temp->right==NULL)
            {
                return NULL;
            }
            else 
            {
                return find_node(n,temp->right);
            }
        }


    }


    void deletion()
    {
        if(root==NULL)
        {
            printf("node is not available\n");
            return;

        }

        int n;
        printf("Enter node data to delete: ");
        scanf("%d",&n);

        if(root->data==n)
        {
            tree* temp=root;
            if(root->left!=NULL && root->right==NULL)
            {
               root=root->left;
               free(temp); 
            }
            else if(root->left==NULL && root->right!=NULL)
            {
                root=root->right;
                free(temp);
            }
            else if(root->left==NULL && root->right==NULL)
            {
                root=NULL;
                free(temp);
            }
            else
            {
                tree* pred_parent=root;
                tree* pred=temp->left;

                while(pred->right!=NULL)
                {
                    pred_parent=pred;
                    pred=pred->right;
                }
                root->data=pred->data;

                if(pred->left!=NULL)
                {
                    pred_parent->right=pred->left;
                   
                }
                else
                {
                    pred_parent->right=NULL;

                }
                free(pred);
            }

            return;
        }

        tree* parent=find_node(n,root);  //parent node of node  to delete
        tree* dnode;  // node to delete
        


        if(parent->left->data>n)
        {
            dnode=parent->left;
        

        if(dnode->left!=NULL && dnode->right==NULL)
        {
            parent->left=dnode->left;
            free(dnode);
        }
        else if(dnode->left==NULL && dnode->right!=NULL)
        {
            parent->left=dnode->right;
            free(dnode);
        }
        else if(dnode->left==NULL && dnode->right==NULL)
        {
            parent->left=NULL;
            free(dnode);
        }
        else
        {
            
                tree* pred_parent=dnode;
                tree* pred=dnode->left;

                while(pred->right!=NULL)
                {
                    pred_parent=pred;
                    pred=pred->right;
                }

                dnode->data=pred->data;

                if(pred->left!=NULL)
                {
                    pred_parent->right=pred->left;
                }
                else
                {
                    pred_parent->right=NULL;
                }
                free(pred);


        }
        }

        else
        {
            dnode=parent->right;

        if(dnode->left!=NULL && dnode->right==NULL)
        {
            parent->left=dnode->left;
            free(dnode);
        }
        else if(dnode->left==NULL && dnode->right!=NULL)
        {
            parent->left=dnode->right;
            free(dnode);
        }
        else if(dnode->left==NULL && dnode->right==NULL)
        {
            parent->left=NULL;
            free(dnode);
        }
        else
        {
            
                tree* pred_parent=dnode;
                tree* pred=dnode->left;

                while(pred->right!=NULL)
                {
                    pred_parent=pred;
                    pred=pred->right;
                }

                dnode->data=pred->data;

                if(pred->left!=NULL)
                {
                    pred_parent->right=pred->left;
                }
                else
                {
                    pred_parent->right=NULL;
                }
                free(pred);


        }
    }
    }


    




tree* small(tree* temp)
{
    if(temp->left==NULL)
    {
        return temp;
    }
    return small(temp->left);;
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
    insertion();
    insertion();
    insertion();
    insertion();
    insertion();
    insertion();


    display();

    deletion();

    printf("\n");
    display();
    return 0;
}