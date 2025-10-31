#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void display();
typedef struct node
{
    int data;
    struct node* next;
}link;

link* head;

void create()
{
    int e;
    printf("Create a linklist: \n");
    scanf("%d",&e);
    head=(link*) malloc(sizeof(link));
    head->data=e;
    head->next=NULL;
    display();
}

void display()
{
    link* temp=head;
    if(head==NULL)
    {
        printf("\n Linklist is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf(" %d - >",temp->data);
        temp=temp->next;
    }
}



int main()
{
    create();
    return 0;
}