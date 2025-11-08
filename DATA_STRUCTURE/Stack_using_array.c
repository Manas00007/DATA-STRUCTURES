#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

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
while(true)
{
    printf("\n=============MENU STACK USING ARRAY=====================\n");
    printf("--CHOOSE OPTIONS--\n");
    printf("1) PUSH DATA (INSERT DATA IN STACK)\n");
    printf("2) POP DATA (DELETE DATA FROM STACK)\n");
    printf("3) PEEK (GET TOP DATA OF STACK)\n");
    printf("4) DISPLAY STACK DATA\n");
    printf("5) Exit MENU");

    printf("\nChoose the Operation 1 to 5:\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        push();
        break;

        case 2:
        pop();
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