#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int size();
void recall();

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}dlink;

dlink* head;

int size()
{
    dlink* temp=head;
    int size=0;

    while(temp!=NULL)
    {
        temp=temp->next;
        size++;
    }

    return size;

}
void create()
{
int e;
printf("Enter data :");
scanf("%d",&e);

head=(dlink*) malloc(sizeof(dlink));

head->data=e;
head->prev=NULL;
head->next=NULL;
display();

}

void insert_at_end()
{
    int flag=1;
    if(head==NULL)
    {
        create();
        return;
    }
    int e;
    printf("\nEnter data :");
    scanf("%d",&e);

    dlink* new=(dlink*) malloc(sizeof(dlink));
    new->data=e;
if(head->next==NULL)
{
    new->prev=head;
    new->next=NULL;
    head->next=new;

}
else{
    dlink* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    new->prev=temp;
    new->next=NULL;
    temp->next=new;
    
}
display();
recall(flag);
}

void insert_at_front()
{
    int flag=2;
    if(head==NULL)
    {
        create();
        return;
    }
int e;
printf("Enter data :");
scanf("%d",&e);

dlink* new=(dlink*) malloc(sizeof(dlink));
dlink* temp=head;
new->data=e;
new->prev=NULL;
temp->prev=new;
new->next=temp;
head=new;
display();
recall(flag);

}

void insert_at_specific_position()
{
    int flag=3;
    if(head==NULL)
    {
        create();
        return;
    }


    int pos;
    printf("\nEnter position: ");
    scanf("%d",&pos);
    int count=1;
    dlink* temp=head;
    if(pos>size())
    {
        printf("invalid position");
        return;
    }
    else if(pos==1)
    {
        insert_at_front();
        return;
    }
    else{
    while(pos>count)
    {
        temp=temp->next;
        count++;
    }
}
    int e;
    printf("Enter element: ");
    scanf("%d",&e);


    dlink* new=(dlink*) malloc(sizeof(dlink));

    new->data=e;
    new->prev=temp->prev;
    new->next=temp;
    temp->prev->next=new;
    temp->prev=new;
    display();
    recall(flag);


}

void delete_from_end()
{
  int flag=4;
  dlink* temp=head;
  if(head==NULL)
  {
    printf("linklist is  not available or empty");
    return;
  }
  else if(head->next==NULL)
  {
    dlink* temp=head;
    int d=temp->data;
    head=NULL;
    free(temp);
    printf("\n %d is Deleted.Now linklist is empty\n",d);

    return;
  }
  else{
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    dlink* temp2=temp->next;
    temp->next=NULL;
    free(temp2);

  }
display();
recall(flag);

}

void delete_from_front()
{
    int flag=5;
    if(head==NULL)
    {
        printf("\nlinklist is empty\n");
        
    }
    else if(head->next==NULL)
    {
        dlink* temp=head;
        int d=temp->data;
        free(temp);
        head=NULL;
        printf("\n %d is Deleted.Now linklist is empty\n",d);

    }
    else{
        dlink* temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        free(temp);
    }
    display();
    recall(flag);

}

void delete_from_specific_position()
{
    int flag=6;
    if(head==NULL)
    {
        printf("Linklist is empty");
        return;
    }

    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    int count=1;
    dlink* temp=head;


    if(pos==1 && head->next==NULL)
    {
       delete_from_front();
        

    }
    else if (pos>size())
    {
        printf("Invalid position!\n");
    }
    
    else{
        while(pos>count)
        {
            temp=temp->next;
            count++;
        }

        if(pos!=1)
        {
        temp->prev->next=temp->next;
        free(temp);
    }
    else{
        delete_from_front();
    }
}
display();
recall(flag);

}

void display()
{
    dlink* temp=head;
if(head==NULL)
{
    printf("\nLinklist is empty\n");
    return;
}
    while(temp!=NULL)
    {
       printf("<-> %d",temp->data);
       temp=temp->next; 
    }
}

void free_memory()
{
    dlink* temp=head;
    dlink* next_node;

    while(temp!=NULL)
    {
        next_node=temp->next;
        free(temp);
        temp=next_node;
    }
    head=NULL;
}

void recall(int x)
{
    char ch;
        printf("\nDo you want to continue inserting from end..\n");
        printf("press y OR Y for YES & n or N for NO: ");
        scanf(" %c",&ch);
        

        if(ch=='n'|| ch=='N')
        {
                return;
            }

        else if(ch=='y'||ch=='Y'){
            if(x==1)
            {
                insert_at_end();
            }
            else if(x==2)
            {
                insert_at_front();
            }
            else if(x==3)
            {
                insert_at_specific_position();
            }
            else if(x==4)
            {
                delete_from_end();
            }
            else if(x==5)
            {
                delete_from_front();
            }
            else if(x==6)
            {
                delete_from_specific_position();
            }
            else{
                return;
            }
        }
        else{
            printf("invaild input");
        }
}

int main()
{
 while(true)
 {
    printf("\n=========DOUBLY LINKLIST OPERATIONS MENU========\n");
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
