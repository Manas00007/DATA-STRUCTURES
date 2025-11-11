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

void enqueue()
{

    int n;
    printf("Enter data: ");
    scanf("%d",&n);
    int p;
    printf("\nEnter the priority number: ");
    scanf("%d",&p);

    pqueue* new=(pqueue*) malloc(sizeof(pqueue));
    new->data=n;
    new->prio=p;
    if(front==NULL)
    {
    new->next=NULL;
     front=new;
     rear=new;

    }
    else if(front->next==NULL)
    {
        if(front->prio>p)
        {
            front->next=new;
            rear=new;
        }
        else
        {
            new->next=front;
            front=new;
        }
    }
    else
    {
        pqueue* temp=front;
        while( temp->next!=NULL && temp->next->prio>=p )
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            rear=new;
        }
        new->next=temp->next;
        temp->next=new;
        
    }

    printf("\n %d is successfully inserted\n",n);
}


void dequeue()
{
    
    if(front==NULL)
    {
        printf("\n Queue underflow\n");
        return;
    }
    int n=front->data;
    int m=front->prio;

    if(front->next==NULL)
    {
        rear=NULL;
        free(front);
        front=NULL;
    }
    else
    {

        pqueue* temp=front;
        front=temp->next;
        free(temp);


    }

    printf("\n%d with priority %d is deleted fromt Queueu\n",n,m);

}



void peek()
{
    if(front==NULL)
    {
        printf("\n Queueu is empty\n");
        return;
    }
    printf("\n%d is front and high priority element with priority %d\n",front->data,front->prio);
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

void free_memory()
{
    pqueue* temp=front;
    while(front!=NULL)
    {
        temp=front->next;
        free(front);
        front=temp;
    }
    front=NULL;
    rear=NULL;
}

int main()
{

   while(true)
   {
    printf("\n -------------PRIORITY QUEUE MENU-----------\n");
    printf("==========SELECT OPERATIONS============\n");
    printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter the choice 1-5\n");
        int ch;
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            free_memory();
            exit(0);
            break;
        }
   }
    return 0;

}