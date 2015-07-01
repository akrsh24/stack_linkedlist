#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node Node;

Node *head;
Node *tail;

void insert(int);
int fetch(int);
void display();
int remove_value(int);
void remove_index(int);
int main(int argc, char *argv[])
{
    int m,ch;
    int choice;
    int value;
    int index;
    while(1)
    {

        printf("What do you want to do?\n\n");
        printf("1. Insert \n2. Fetch \n3. Display \n4. Remove  \n5. Exit \n");

        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the value you want to insert!\n");
            scanf("%d", &value);
            insert(value);
            printf("\nInserted the value %d into linkedList\n", value);
            break;
        case 2:
            printf("\nValue at what index you want to fetch\n");
            scanf("%d", &index);
            value = fetch(index);
            printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
            break;
        case 3:
            printf(" Displaying: \n");
            display();
            break;
        case 4:

            printf(" \n 1. BY INDEX\n");
            printf(" \n 2. BY VALUE\n");
            printf("what you want to enter\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("enter the index\n");
                scanf("%d",&m);
                remove_index(m);
                break;
            case 2:
                printf("enter the value\n");
                scanf("%d",&m);
                remove_value(m);
                break;
            }
            break;

        case 5:
            printf("\nExiting...\n");
            return 0;
        default:
            break;
        }
    }
}

void insert (int value)
{
    if(head==NULL)
    {

        head=(Node *)malloc(sizeof(Node));
        head->value=value;
        head->next=NULL;
        tail=head;
    }
    else
    {
        tail->next=(Node *)malloc(sizeof(Node));
        tail->next->value=value;
        tail->next->next=NULL;
        tail=tail->next;
    }
}
int fetch(int index)
{
    int i;
    if(head==NULL)
    {
        return -1;
    }
    Node *ptr=head;
    for(i=0; i<index; i++)
    {
        if(ptr->next=NULL)
        {


            return -1;
        }
        ptr=ptr->next;
    }
    return ptr->value;
}
void display()
{

    if (head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        Node *ptr=head;
        while(ptr!=NULL)
        {
            printf("\n %d \n",ptr->value);
            ptr=ptr->next;
        }

    }
}
int remove_value(int val)
{
    Node *ptr=head;
    if(ptr==NULL)
    {
        printf("linked list not exist\n ");
        return -1;

    }
    else
    {
        if(ptr->value==val)
        {
            head=head->next;
            return 0;
        }
        Node *p=head;
        while(ptr!=NULL)
        {
            if(p->value==val)
            {
                ptr->next=ptr->next->next;

                printf("value at %d is removed\n",val);
            }
            p=p->next;
            if(p->value==val)
            {
                ptr->next=p->next;
            }
            ptr=p->next;
            p=p->next;
        }
    }
}
void remove_index(int index)
{
    int i,k=0;
    Node *ptr=head;
    if(ptr==NULL)
    {
        printf("linked list not exist\n ");
        return -1;

    }
    else
    {
        if(index==0)
        {
            head=head->next;
            return 0;
        }
        for(i=0; i<index-1; i++)
        {
            k++;
            ptr=ptr->next;

        }
        ptr->next=ptr->next->next;
        printf("value at %d is removed\n",index);
    }

}

