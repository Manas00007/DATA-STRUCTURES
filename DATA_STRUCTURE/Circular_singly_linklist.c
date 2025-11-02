#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void display();
int size();
void recall();
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
    int flag=1;
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
    recall(flag);
    // display();
 }       

 void insert_at_end()
 {
    int flag=2;
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
    recall(flag);
    // display();
 }

 void insert_at_specific_position()
 {
    int flag=3;
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
    recall(flag);
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
    int flag=4;
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
    recall(flag);

 }


 void delete_from_end()
 {
    int flag=5;
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
    recall(flag);

 }
    
 void delete_from_specific_position()
 {
    int flag=6;
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
    recall(flag);
    
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

void recall(int x)
{
    printf("Do you want to continue...");
    printf("\nPress(Y/y) for YES Or (N/n) for NO\n");
    char ch;
    scanf(" %c",&ch);
    if(ch=='y' || ch=='Y')
    {
        if(x==1)
        {
            insert_at_front();
        }
        else if(x==2)
        {
            insert_at_end();
        }
        else if(x==3)
        {
            insert_at_specific_position();

        }
        else if(x==4)
        {
            delete_from_front();

        }
        else if(x==5)
        {
            delete_from_end();
            
        }
        else
        {
            delete_from_specific_position();
        }

    }
    else if(ch=='n' || ch=='N')
    {
        return;
    }
    else
    {
        printf("\nINVALID\n");
    }
}

void free_memory()
{
    clink* temp=head;
    clink* next_node;

    while(temp->next!=head)
    {
        next_node=temp->next;
        free(temp);
        temp=next_node;
    }
    free(temp);
    head=NULL;

}


int main()
{

   while(true)
 {
    printf("\n=========CIRCULAR SINGLY LINKLIST OPERATIONS MENU========\n");
    printf("1. CREATE LINKLIST\n");
    printf("2. INSERT AT FRONT\n");
    printf("3. INSERT AT SPECIFIC POSITION\n");
    printf("4. INSERT AT END\n");
    printf("5. DELETE FROM FRONT\n");
    printf("6. DELETE FROM SPECIFIC POSITION\n");
    printf("7. DELETE FROM END\n");
    printf("8. TOTAL NUMBER OF ELEMENTS\n");
    printf("9. DISPLAY\n");
    printf("10. EXIT\n");

    int choice;
    printf("Enter Your Choice <1-10>");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        create();
        break;
        case 2:
        insert_at_front();
        break;
        case 3:
        insert_at_specific_position();
        break;
        case 4:
        insert_at_end();
        break;
        case 5:
        delete_from_front();
        break;
        case 6:
        delete_from_specific_position();
        break;
        case 7:
        delete_from_end();
        break;
        case 8:
        printf("\nThe size of linklist is :%d\n",size());
        break;
        case 9:
        display();
        break;
        case 10:
        free_memory();
        exit(0);
        break;
    }
 }
    return 0;
}