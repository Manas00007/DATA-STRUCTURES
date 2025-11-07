#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}stack;

stack* top=NULL;



void push()
{

    int n;
    printf("Enter data: ");
    scanf("%d",&n);

    stack* new=(stack*) malloc(sizeof(stack));
    new->data=n;
    
    if(top==NULL)
    {
        new->next=NULL;
        top=new;
        
    }
    else
    {

    
    new->next=top;
    top=new;
}


    printf("\n %d is successfully pushed into the stack\n",n);

}

void pop()
{
    if(top==NULL)
    {
        printf("Stack underflow\n");
        return;
    }

    int x=top->data;

    if(top->next==NULL)
    {
       
        free(top);
        top=NULL;
    
    }
    else
    {

    stack* temp=top;
    top=temp->next;
    temp->next=NULL;
    free(temp);

}
 printf("\n %d is successfully poped from the stack\n",x);
    
}

void display()
{
    if(top==NULL)
    {
        printf("Stack is empty..");
        return;
    }

    stack* temp=top;

    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void peek()
{

    if(top==NULL)
    {
        printf("\n stack is empty..\n");
    }
    else
    {
    printf("\n %d is top of stack\n",top->data);
    }
}


void free_memory()
{
    stack* temp=top;
    

    while(top!=NULL)
    {
        temp=top;
        top=top->next;
        free(temp);
        
    }
    ;
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

    pop();
    pop();

    
    display();
    return 0;
}