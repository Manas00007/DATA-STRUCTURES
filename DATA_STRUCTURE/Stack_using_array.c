#include<stdio.h>

#define MAX 100
int stack[MAX];
int top=-1;

int is_empty()
{
        
        return top==-1;
    
}

int is_full()
{
    
        
        return top==MAX-1;
    
}

void push()
{
    if(is_full())
    {
        printf("stack overflow.\n");
        return;
    }

    top++;
    int n;
    printf("Enter data: ");
    scanf("%d",&n);
    stack[top]=n;
    printf("\n%d is successfully pushed into stack\n",n);
}


void pop()
{
    if(is_empty())
    {
        printf("\nstack underflow");
        return;
    }
    int n=stack[top];
    top--;
    printf("\n%d is successfully poped from the stack\n",n);

}


void peek()
{
    printf("%d is in the top of the stack\n",stack[top]);
}

void display()
{
    int i=0;
    while(i<=top)
    {
        printf(" %d",stack[i]);
        i++;
    }
    printf("\n");
}
int main()
{
push();
push();
push();
push();
display();
pop();
pop();
display();
peek();
display();
return 0;
}