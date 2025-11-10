#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    int prio;
    struct node* next;
}pqueue;

pqueue* front=NULL;
pqueue* rear=NULL;

void enqueue(int p)
{

    int n;
    printf("Enter data: ");
    scanf("%d",&n);

    pqueue* new=(pqueue*) malloc(sizeof(pqueue));
    new->data=n;
    new->prio=p;
    if(front==NULL)
    {
    new->next=NULL;
     front=new;
     rear=new;

    }
    else{
        pqueue* temp=front;
   while(temp->next!=NULL && temp->next->prio>=p)
   {
         temp=temp->next;
   }
    new->next=temp->next;
    temp->next=new;
}

    printf("\n %d is successfully inserted\n",n);
}

void display()
{
    if(front==NULL)
    {
        printf("\n queue is empty");
        return;
    }

    pqueue* temp=front;
    while(temp!=NULL)
    {
        printf("\n%d with priority %d",temp->data,temp->prio);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{

    enqueue(4);
    enqueue(2);
    enqueue(1);
    enqueue(3);



    display();
    return 0;

}