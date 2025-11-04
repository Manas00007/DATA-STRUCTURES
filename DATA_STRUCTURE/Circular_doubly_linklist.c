#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int size();

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

void insert_at_specific_position()
{
    if(head==NULL)
    {
        create();
        return;
    }
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    int count=1;
    cdlink* temp=head;
    if(pos>size())
    {
        printf("Invalid position..");
        return;
    }
    if(pos==1)
    {
        insert_at_front();
        return;
    }

    while(pos>count)
    {
        temp=temp->next;
        count++;
    }

    int e;
    printf("Enter data: ");
    scanf("%d",&e);
    cdlink *new=(cdlink*) malloc(sizeof(cdlink));

    new->data=e;
    new->prev=temp->prev;
    temp->prev->next=new;
    new->next=temp;
    temp->prev=new;


}

void delete_from_front()
{
    if(head==NULL)
    {
        printf("Linklist is empty");
        return;
    }

    cdlink* temp=head;

    if(head->next==head)
    {
        head=NULL;
        free(temp);
        return;
    }

    head=temp->next;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);


}

void delete_from_end()
{
    if(head==NULL){
        printf("\n linklist is empty..");
        return;
    }

    if(head->next==head)
    {
        delete_from_front();
        return;
    }

    cdlink* temp=head->prev;
    temp->prev->next=head;
    head->prev=temp->prev;
    free(temp);



}
void delete_from_specific_position()
{
    if(head==NULL)
    {
        printf("Linklist empty..");
        return;
    }
    int pos;
    printf("Enter the position");
    scanf("%d",&pos);

    if(pos==1)
    {
        delete_from_front();
        return;
    }

    if(pos>size())
    {
        printf("Invalid position..");
        return;
    }
    int count=1;

    cdlink* temp=head;
    while(pos>count)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
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

int size()
{
    int x=1;
    cdlink* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
        x++;
    }

    return x;
}


int main()
{
    create();
    // insert_at_front();
    // insert_at_front();
    // insert_at_front();
    // insert_at_front();
    // insert_at_end();
    // insert_at_end();
    // insert_at_end();
    // insert_at_end();
    delete_from_specific_position();
    


    display();

    return 0;
}