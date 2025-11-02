#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void display();
int size();
typedef struct node
{
    int data;
    struct node* next;
}clink;

clink* head;


void create()
{
    int e;
    printf("create a linklist: ");
    scanf("%d",&e);

    head=(clink*) malloc(sizeof(clink));

    head->data=e;
    head->next=head;
    // display();
}


 void insert_at_front()
 {
    if(head==NULL)
    {
        create();
        return;
    }

    int e;
    printf("Enter data:\n");
    scanf("%d",&e);

    clink* new=(clink*) malloc(sizeof(clink));
    clink* temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    new->data=e;
    new->next=head;
    temp->next=new;
    head=new;
    
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
        printf("Enter data: ");
        scanf("%d",&e);
        clink* new=(clink*) malloc(sizeof(clink));
        clink* temp=head;
        new->data=e;
        new->next=head;
        
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=new;
    
    // display();
 }

 void insert_at_specific_position()
 {
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    int count=2;

    if(pos>size())
    {
        printf("\ninvalid position...");
        return;
    }
    if(pos==1)
    {
        insert_at_front();
        return;
    }
    clink* temp=head;
    while(pos>count)
    {
        count++;
        temp=temp->next;
    }

    int e;
    printf("Enter data: ");
    scanf("%d",&e);
    clink* new=(clink*) malloc(sizeof(clink));
    new->data=e;
    new->next=temp->next;
    temp->next=new;

 }

 int size()
 {
    int count=1;
    clink* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
        count++;
    }

    return count;
 }


 void delete_from_front()
 {
    if(head==NULL)
    {
        printf("Linklist is empty..\n");
        return;
    }
    clink* temp=head;
    clink* temp2=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    if(temp2->next==head)
    {
        head=NULL;
        free(temp2);
        return;
    }
    head=temp2->next;
    temp->next=head;
    free(temp2);

 }


 void delete_from_end()
 {
    if(head==NULL)
    {
        printf("Linklist is empty..\n");
        return;
    }
    clink* temp=head;

    if(temp->next==head)
    {
        head=NULL;
        free(temp);
        return;
    }
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }

    clink* temp2=temp->next;
    temp->next=head;
    free(temp2);

 }
    
 void delete_from_specific_position()
 {
    if(head==NULL)
    {
        printf("Linklis is empty..\n");
        return;
    }

    int pos;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    int count=2;
    clink* temp=head;
    if(pos==1){

        delete_from_front();
        return;
        
    }


    while(pos>count)
    {
        temp=temp->next;
        count++;
    }
    clink* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    
    


 }




void display()
{
    clink* temp=head;
    if(temp==NULL)
    {
        printf("\nLinklist is empty...\n");
        return;
    }
    if(temp->next==head)
    {
        printf("%d->",temp->data);
        return;
    }

    while(temp->next!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
        printf("%d->",temp->data);

        printf("\n");



}

int main()
{

    create();

    insert_at_end();
    insert_at_end();
    insert_at_end();

    // insert_at_end();

    // insert_at_end();
    display();

    // delete_from_front();
    delete_from_specific_position();
    
    // insert_at_specific_position();
    // printf("\nthe size of linklist is %d ",size());


    // insert_at_front();
    // insert_at_front();
    // insert_at_front();
    display();
    return 0;
}