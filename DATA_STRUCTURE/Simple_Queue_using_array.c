#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100


int queue[MAX];
int front=-1;
int rear=-1;

int is_empty()
{
    return front==-1;
}

int is_full()
{
    return rear==MAX-1;
}


void Enqueue()
{
    

    if(is_full())
    {
        printf("Queue overflow\n");
        return;
    }

    int n;
    printf("Enter element: ");
    scanf("%d",&n);


    if(is_empty())
    {
        front=0;
        rear=0;
    }
    else
    {
        rear++;
    }

    queue[rear]=n;

    printf("\n%d is successfuly enqueue in the Queue\n",n);

}


void dequeue()
{
    if(is_empty())
    {
        printf("\nQueue underflow\n");
        return;

    }


    int n=queue[front];
    if(rear==front)
    {
        rear=-1;
        front=-1;
     
    }
    else
    {
    front++;
    }
    printf("\n%d is successfuly denqueue from the Queue\n",n);

}

void peek()
{
    if(is_empty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\n%d is a recent element of the queue\n",queue[rear]);
}



void display()
{
    if(is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    int i=front;
    while(i<rear)
    {
        printf(" %d",queue[i]);
        i++;
    }
    printf(" %d",queue[i]);


    printf("\n");
}

int main()
{

    while(true)
    {
        printf("\n---------------------Queue using Array Operation Menu----------------------\n");
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
            Enqueue();
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
            exit(0);
            break;
        }
    }
    return 0;
}