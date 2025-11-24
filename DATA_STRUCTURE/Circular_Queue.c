#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node* next;
}cqueue;

cqueue* front=NULL;
cqueue* rear=NULL;


void enqueue()
{

    int n;
    printf("\n Enter data: ");
    scanf("%d",&n);

    cqueue* new= (cqueue*) malloc(sizeof(cqueue));

    new->data=n;

    if(front==NULL)
    {
        new->next=new;
        rear=new;
        front=new;
    
    }
    else
    {

        new->next=front;
        rear->next=new;
        rear=new;
    }

    printf("\n%d is successfully  inserted\n",n);
}

void dequeue()
{
    if(front==NULL)
    {
        printf("\nqueue overflow / queue is empty\n");
        return;
    }
    int x=front->data;

    if(front==rear)
    {
        rear=NULL;
        free(front);
        front=NULL;
        return;
    }
    else
    {
        cqueue* temp=front;
        rear->next=front->next;
        front=temp->next;
        free(temp);

    }

    printf("\n%d is successfully deleted from the Queue\n",x);
}


void peek()+
{
    if(front==NULL)
    {
        printf("\n Queue is empty\n");
        return;
    }
    printf("\n%d is the front of Queue\n",front->data);

}

void display()
{
    if(front==NULL)
    {
        printf("\n queue is empty\n");
        return;
    }
    cqueue* temp=front;
    while(temp!=rear)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf(" %d",temp->data);

}

void free_memory()
{
    cqueue*temp=front;
    while(front!=rear)
    {
        temp=front->next;
        free(front);
        front=temp;
    }
    free(front);
    front=NULL;
    rear=NULL;
}


int main()
{


    while(true)
    {
        printf("\n---------------------Circular Queue Operation Menu----------------------\n");
        printf("------Queue Operations-----");
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