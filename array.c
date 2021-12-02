#include <stdio.h>
void display(int arr[]);
void search(int arr[]);
void insert(int arr[]);
void delete(int arr[]);

int n;
void main(){
    int a,j=1;
    printf("Enter the number of elements in an array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    do
    {
        printf("\n*****Select the operation******\n\n\t1. Search\n\t2. Insert\n\t3. Delete\n\t4. Display\n\t5. Exit\n>>");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            search(arr);
            break;
        case 2:
            insert(arr);
            break;
        case 3:
            delete(arr);
            break;
        case 4:
            printf("Array: ");
            display(arr);
            break;
        case 5:
            j=0;
            break;

        default:
            printf("\nError: The selected operation not found.\nTry again\n");
            break;
        }
    } while (j!=0);
    
}

void display(int arr[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void search(int arr[]){
    int key,flag=1;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            printf("\nThe element \"%d\" found at the position \"%d\"\n",key,i+1);
            flag=0;
        }
    }
    if(flag==1){
        printf("\nError: The element \"%d\" not found\n",key);
    }
    
}

void insert(int arr[]){
    int val,index;
    printf("Enter the element to be inserted: ");
    scanf("%d",&val);
    printf("Enter the position of the element to be inserted: ");
    scanf("%d",&index);
    for (int i = n; i >= index; i--){
        arr[i]=arr[i-1];
    }
    arr[index-1]=val;
    n++;
    printf("\nThe element \"%d\" inserted successfully\nArray: ",val);
    display(arr);
    printf("\n");
}

void delete(int arr[]){
    int key,flag=0,index;
    printf("Enter the element to be deleted: ");
    scanf("%d",&key);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            index=i;
            flag=1;
            break;
        }
    }
    if(flag==1){
        for (int i = index; i < n-1; i++)
        {
            arr[i]=arr[i+1];
        }
        n--;
        printf("\nThe element \"%d\" deleted successfully\nArray: ",key);
        display(arr);
        printf("\n");
    }else{
        printf("\nError: The element \"%d\" not found\n",key);
    }
}