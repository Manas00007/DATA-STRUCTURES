#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}cdlink;

cdlink* head;


void create()
{
    int e;
    printf("\n create linklist: ");
    scanf("%d",&e);

    head=(cdlink*) malloc(sizeof(cdlink));

    head->data=e;
    head->prev=head;
    head->next=head;

}

void insert_at_front()
{
    if(head==NULL)
    {
        create();
        return;
    }

    int e;
    printf("\n Enter data: ");
    scanf("%d",&e);

    cdlink* new=(cdlink*) malloc(sizeof(cdlink));

    cdlink* temp=head;

    new->data=e;
    new->next=temp;
    temp->prev->next=new;
    new->prev=temp->prev;
    temp->prev=new;
    head=new;

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

    cdlink* new=(cdlink*) malloc(sizeof(cdlink));
    
    new->data=e;
    new->prev=head->prev;
    head->prev->next=new;
    new->next=head;
    head->prev=new;

}

void display()
{
    if(head==NULL)
    {
        printf("\n linklist is empty..\n");
    }

    cdlink* temp=head;
    while(temp->next!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->",temp->data);
}




int main()
{
    create();
    // insert_at_front();
    // insert_at_front();
    // insert_at_front();
    // insert_at_front();
    insert_at_end();
    insert_at_end();
    insert_at_end();
    insert_at_end();


    display();
    return 0;
}