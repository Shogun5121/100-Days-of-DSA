#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* Temp = NULL;

Node* createdoublylist(int *arr, int n) {
    
    if(n==0)
    {
        return NULL;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = arr[0];
    newnode->next = createdoublylist(arr+1, n-1);
    
    if(newnode->next!=NULL)
    {
        newnode->next->prev = newnode;
    }

    return newnode; 

}

int main() {

    Node* Temp = NULL;
    int n;
    
    printf("Enter no. of elements of an array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter list elements: ");

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    Node* Head = createdoublylist(arr, n);

    for(Temp = Head; Temp!=NULL; Temp = Temp->next)
    {
        printf("%d ", Temp->data);
    }

    return 0;

}