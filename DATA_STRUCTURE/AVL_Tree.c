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

void insert()
{
    if(root==NULL)
    {
        printf("Avl tree is empty\n");
        return;
    }
}
int main()
{
    return 0;
}