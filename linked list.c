#include <stdio.h>
#include <stdlib.h>
void display();
void search();
void insert();
void insertatstart();
void insertatlast();
void insertafterele();
void delete();

struct linkedlist{
    int data;
    struct linkedlist *next;
};

struct linkedlist *head = NULL;

void main(){
    int a;
    do
    {
        printf("\n*****Select the operation******\n\n\t1. Insert\n\t2. Delete\n\t3. Search\n\t4. Display\n\t5. Exit\n>>");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            search();
            break;
        case 4:
            printf("\nlinkedlist: ");
            display();
            printf("\n");
            break;
        case 5:
            break;

        default:
            printf("\nError: Invalid input\nTry again\n");
            break;
        }
    } while (a!=5);
    
}

void insert(){
    int b;
    printf("\nwhere to insert?");
    printf("\n1. At the beginning of linked list");
    printf("\n2. At the end of linked list");
    printf("\n3. After an element\n");
    scanf("%d",&b);
    switch (b)
    {
        case 1:
            insertatstart();
            break;
        case 2:
            insertatlast();
            break;
        case 3:
            insertafterele();
            break;
    
    default:
        printf("\nError: Invalid input\nTry again\n");
        break;
    }
}
void insertatstart(){
    int d;
    printf("Enter element to insert:");
    scanf("%d",&d);

    struct linkedlist *temp = malloc(sizeof(struct linkedlist));
    temp->data = d;
    if(head!=NULL){
        temp->next = head;
        head = temp;
    }else{
        temp->next=NULL;
        head=temp;
    }
    printf("\nElement inserted successfully");
    printf("\nlinkedlist: ");
    display();
    printf("\n");
}
void insertatlast(){
    int d;
    printf("Enter element to insert:");
    scanf("%d",&d);

    struct linkedlist *temp = malloc(sizeof(struct linkedlist));
    temp->data = d;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }else{
        struct linkedlist *templist = head;
        while (templist->next!=NULL)
        {
            templist=templist->next;
        }
        templist->next=temp;
    }
    printf("\nElement inserted successfully");
    printf("\nlinkedlist: ");
    display();
    printf("\n");
}
void insertafterele(){
    int c,d,flag=0;
    printf("\nlinkedlist: ");
    display();
    printf("\n");
    printf("\nEnter element to insert: ");
    scanf("%d",&c);
    struct linkedlist *temp = head;
    struct linkedlist *new = malloc(sizeof(struct linkedlist));
    new->data=c;
    if(head==NULL){
        new->next=NULL;
        head=new;
        printf("\nlinkedlist: ");
        display();
        printf("\n");
    }else{
        printf("\nEnter the previous element: ");
        scanf("%d",&d);
        
        
        while (temp!=NULL)
        {
            if(temp->data==d){
                new->next=temp->next;
                temp->next=new;
                flag=1;
                printf("\nElement inserted successfully");
                printf("\nlinkedlist: ");
                display();
                printf("\n");
                break;
            }
            temp=temp->next;
        }
        if(flag==0){
            printf("\nError: Previous element not found\n");
        }
    }
}

void display(){
    struct linkedlist *temp = head;
    if(temp==NULL){
        printf("empty");
    }else{
        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            if(temp->next!=NULL){
                printf("-> ");
            }
            temp=temp->next;
        }
    }
}

void delete(){
    int b,flag=0;
    printf("\nEnter element to delete: ");
    scanf("%d",&b);
    struct linkedlist *temp = head;
    if(temp==NULL){
        printf("\nError: linkedlist is empty");
    }else{
        if(temp->data==b){
            head = temp->next;
            printf("\nElement deleted successfully");
            printf("\nlinkedlist: ");
            display();
            printf("\n");
        }else{
            
            struct linkedlist *current  = head;
            while(current->next != NULL)
            {
                if(current->next->data == b)
                {
                    temp = current->next;
                    current->next = current->next->next;
                    flag=1;
                    printf("\nElement deleted successfully");
                    printf("\nlinkedlist: ");
                    display();
                    printf("\n");
                    break;
                }
                else
                    current = current->next;
            }
            if(flag==0){
                printf("\nError: Element not found");
            }
        }
    }
}

void search(){
    int c,flag=0,count=1;
    struct linkedlist *temp = head;
    if(temp==NULL){
        printf("Error: linkedlist is empty\n");
    }else{
        printf("\nEnter element to search: ");
        scanf("%d",&c);
        
        while (temp!=NULL)
        {
            if(temp->data==c){
                printf("Element found at position %d",count);
                flag=1;
            }
            temp=temp->next;
            count++;
        }
        if(flag==0){
            printf("\nError: Element not found\n");
        }
    }
}
