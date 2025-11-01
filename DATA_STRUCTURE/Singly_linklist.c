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
    printf("Create a linklist:");
    scanf("%d",&e);
    head=(link*) malloc(sizeof(link));
    head->data=e;
    head->next=NULL;
    // display();
}

void insert_at_end()
{
    if(head==NULL)
    {
        create();
        return;
    }

    int e;
    printf("\nEnter data: ");
    scanf("%d",&e);
    link* new=(link*) malloc(sizeof(link));
    link* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    new->data=e;
    new->next=NULL;
    temp->next=new;

}

void insert_at_front()
{
    if(head==NULL)
    {
        create();
        return;
    }
    int e;
    printf("\nEnter data:");
    scanf("%d",&e);
    link* new=(link*) malloc(sizeof(link));
    link* temp=head;

    new->data=e;
    new->next=temp;
    head=new;

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
    // insert_at_end();
    // insert_at_end();
    // insert_at_end();
    insert_at_front();
    display();
    return 0;
}