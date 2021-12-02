#include<stdio.h>
#include<stdlib.h>

#define size 10
struct node
{
   int data;
   struct node *next;
};

struct node*chain[size];
void init()
{
  int i;
  for(i=0;i<size;i++)
      {
         chain[i] = NULL;
      }
}
void insert(int value)
{
  struct node*newnode = malloc(sizeof(struct node));
  newnode->data = value;
  newnode->next = NULL;
  
  int key = value%size;
  
  if(chain[key]== NULL)
       {
         chain[key] = newnode;	  
       }
  else
       {
         struct node*temp = chain[key];
         while(temp->next)
         {
           temp = temp->next;     
         }
         temp->next = newnode;  
       }
}
void print()
{
  int i;
  for(i=0;i<size;i++)
  {
    struct node *temp = chain[i];
    printf("chain[%d]-->",i);
    while(temp)
    {
       printf("%d-->",temp->data);
       temp = temp->next;
    }
    printf("NULL\n");
  }
}

int flag = 1;

void main()
{
   init();
   int n,ch;
   printf("\nOPERATIONS------");
   printf("\n 1)INSERTION OF AN ELEMENT");
   printf("\n 2)PRINT THE HASH ARRAY");
   printf("\n 3)EXIT THE PROGRAM"); 
   while(flag==1)
   {
      printf("\nENTER YOUR CHOICE:");
      scanf("%d",&ch);
      switch(ch)
      {
         case 1 :printf("\nEnter the element to be inserted:");
                 scanf("%d",&n);
                 insert(n);break;
         case 2 :print();break;
         case 3 :flag=0;
                 printf("\n-----------------PROGRAM ENDED-------------------\n");
          break;
		  default: printf("\nWRONG CHOICE\n");break;      
      }
   };
}
