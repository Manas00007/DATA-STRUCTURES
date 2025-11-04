#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void display();
int size();
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

void insert_from_specific_position()
{
    if(head==NULL)
    {
        create();
        return;
    }
    int pos;
    printf("\nEnter the position:");
    scanf("%d",&pos);
    int count=1;

    int e;
    printf("Enter data: ");
    scanf("%d",&e);

    link* new=(link*) malloc(sizeof(link));

    if(pos==1)
    {
        insert_at_front();
        return;
    }
    link* temp=head;

    while(pos-1>count)
    {
        temp=temp->next;
        count++;

    }
    link* temp2=temp->next;
    new->data=e;
    new->next=temp2;
    temp->next=new;

    
}

void delete_from_front()
{
    if(head==NULL)
    {
        create();
        return;
    }


    link* temp=head;

    if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
        return;
    }

    head=temp->next;
    free(temp);
}


void delete_from_end()
{
    if(head==NULL)
    {
        printf("Linklist is empty..");
        return;
    }
    link* temp=head;
    if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
        return;

    }
    int count=1;

    
    while(count<size()-1)
    {
        temp=temp->next;
        count++;
    }

    link* temp2=temp->next;
    temp->next=NULL;
    free(temp);
}

void delete_from_specific_position()
{
    if(head==NULL)
    {
        printf("Linklist is empty..");
        return;
    }
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);

    if(pos==1)
    {
        delete_from_front();
        return;
    }

    if(pos>size())
    {
        printf("Invalid position");
        return;
    }

    link* temp=head;
    int count=1;
    while(count<pos-1)
    {
        temp=temp->next;
        count++;
    }

    link* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}

int size()
{
    link* temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
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
    insert_at_end();
    insert_at_end();
    insert_at_end();
    // insert_at_front();
    delete_from_specific_position();
    display();
    return 0;
}