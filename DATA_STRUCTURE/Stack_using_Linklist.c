#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}stack;

stack* head;
stack* top;



void push()
{

    int n;
    printf("Enter data: ");
    scanf("%d",&n);

    stack* new=(stack*) malloc(sizeof(stack));
    new->data=n;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        top=head;
        return;
    }
    
    top->next=new;
    top=new;

}

void pop()
{
    if(head==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    if(head==top)
    {
        head=NULL;
        free(top);
        return;
    }


    stack* temp=head;

    while(temp->next!=top)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    free(top);
    top=temp;
}

void display()
{
    if(head==NULL)
    {
        printf("Stack is empty..");
    }

    stack* temp=head;

    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void peek()
{
    printf("%d",top->data);
}
int main()
{
    push();
    push();
    push();
    push();
    push();

    display();

    peek();

    
    display();
    return 0;
}