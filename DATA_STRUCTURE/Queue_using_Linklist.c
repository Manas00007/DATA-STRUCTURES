#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
    int data;
    struct node* next;
}queue;

queue* front=NULL;
queue* rear=NULL;


void enqueue()
{
    
    int n;
    printf("\nEnter data: ");
    scanf("%d",&n);

    queue* new=(queue*) malloc(sizeof(queue));

    new->data=n;
    new->next=NULL;
    if(front==NULL)
    {
        front=new;
        rear=new;
    }
    else
   { rear->next=new;
    rear=new;}
    printf("\n%d is successfully enqueued in the Queue\n",n);
}


void dequeue()
{
    if(front==NULL)
    {
        printf("\nQueue underflow..\n");
        return;
    }
    int n=front->data;


    if(front==rear)
    {
        rear=NULL;
        free(front);
        front=NULL;

    }
    else
    {
        queue* temp=front;
        front=temp->next;
        free(temp);
    }

    printf("\n%d is successfully dequed from the Queue\n",n);
}

void peek()
{
    if(front==NULL)
    {
        printf("Queue is empty..\n");
        return;
    }
    printf("%d is the front enqueued element\n",front->data);

}
void display()
{

    if(front==NULL)
    {
        printf("Queue is empty..");
        return;
    }

    queue* temp=front;

    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");


}

void free_memory()
{
    queue* temp=front;
    while(front!=NULL)
    {   temp=front->next;
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
        printf("\n---------------------Queue using Linklist Operation Menu----------------------\n");
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