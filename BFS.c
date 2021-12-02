#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct linkedlist{
    int data;
    struct linkedlist *next;
};

struct v_queue{
    int data;
    struct v_queue *next;
};

struct v_queue *front=NULL;
struct v_queue *rear=NULL;


void insert(struct linkedlist *root[],int src,int des){
    struct linkedlist *list=root[src];
    struct linkedlist *temp=malloc(sizeof(struct linkedlist));
    temp->data=des;
    temp->next=NULL;
    if(list==NULL){
        list=temp;
        root[src]=list;
        return;
    }else{
        while(list->next!=NULL){
            list=list->next;
        }
        list->next=temp;
    }
}

void displayGraph(struct linkedlist *root[],int n){
    
    for(int i=0;i<n;i++){
        printf("\nvertex %d adjacency list: ",i);
        struct linkedlist *list=root[i];
        
        while (list!=NULL)
        {
            printf(" %d ",list->data);
            list=list->next;
        }
    }
}

void enqueue(int a){
    struct v_queue *temp=malloc(sizeof(struct v_queue));
    temp->data=a;
    temp->next=NULL;

    if(front==NULL){
        front=temp;
        rear=temp;
    }else{
        rear->next=temp;
        rear=temp;
    }
}

int dequeue(){
    if(front!=NULL){
        int temp=front->data;
        front=front->next;
        return temp;
    }
}

bool checkenqueue(int a){
    struct v_queue *temp=front;
    while(temp!=NULL){
        if(temp->data==a){
            return false;
        }
        temp=temp->next;
    }
    return true;
}

void bfs(struct linkedlist *root[],int n){
    for(int i=0;i<n;i++){
        if(checkenqueue(i)){
            enqueue(i);
        }
        struct linkedlist *list=root[i];
        while(list!=NULL){
            if(checkenqueue(list->data)){
                enqueue(list->data);
            }
            list=list->next;
        }
        
    }

    printf("\nBFS: ");
    while(front!=rear){
        printf(" %d ",dequeue());
    }
    printf(" %d ",dequeue());
}
void main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    struct linkedlist *root[n];
    for(int i=0;i<n;i++){
        root[i]=NULL;
    }

    for(int i=0;i<n;i++){
        int m;
        printf("\nEnter number of adjacent vertices of vertex %d: ",i);
        scanf("%d",&m);
        printf("\nEnter the adjacency list of vertex %d: ",i);
        for(int j=0;j<m;j++){
            int temp;
            scanf("%d",&temp);
            insert(root,i,temp);
        }
        
    }

    displayGraph(root,n);
    bfs(root,n);
}
