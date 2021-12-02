#include <stdio.h>
#include <stdlib.h>
  void enqueue();
  void dequeue();
  void display();
  void empty();
struct linkedlist
{
 int data;
 struct linkedlist *next;
};
struct linkedlist *front=NULL;
struct linkedlist *rear=NULL;
void main()
{
int a;
do
{
    printf("**Select the operation**\n\n\t 1. Enqueue\n\t 2. Dequeue\n\t 3.Display\n\t 4. Empty\n\t 5. Exit\n ");
    scanf("%d",&a);
 switch(a)
 {
 case 1:
    enqueue();
    break;
 case 2:
    dequeue();
    break;
 case 3:
    printf("\n queue:");
    display();
    break;
 case 4:
    empty();

    break;
 case 5:
    exit(0);
    break;
 case 6:
    break;

  Default:
   printf("\nError: Invalid input\nTry again\n");
   break;
 }
}

while (a!=5);
}

void enqueue()
{
 int val;
 printf("Enter the element:");
 scanf("%d",&val);
 struct linkedlist *temp = malloc(sizeof(struct linkedlist));
 temp->data=val;
 temp->next=NULL;
 if(front==NULL)
{
 front=temp;
 rear=temp;
 }
else
{
 rear->next=temp;
 rear=temp;
 }
}
void dequeue()
{
 if(front!=NULL)
{
 front=front->next;
 }
else
{
 printf("\n Queue is empty");
 }
 printf("\n queue: ");
 display();
 printf("\n");
}
void empty()
{
 front=NULL;
 rear=NULL;
 printf("\n queue: ");
 display();
 printf("\n");
}
void display()
{
 struct linkedlist *temp = front;
 if(temp==NULL)
{
 printf("Empty");
 }
 while (temp!=NULL)
 {
 printf("%d",temp->data);
 if(temp->next!=NULL)
{
printf("->");
 }
 temp=temp->next;
 }
 printf("\n");
}