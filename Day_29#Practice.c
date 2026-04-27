#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node; 

Node* createlist(int n, Node* Head) {

    if (n <= 0) 
    {
        printf("Please enter a valid number of nodes.\n");
        return NULL;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(Head == NULL)
    {
        Head = newnode;
    }
    
    if(n == 1)
    {
        newnode->next = Head; 
        return newnode;
    }

    newnode->next = createlist(n-1, Head); 
    return newnode;

}

void traverse(Node* Head)
{
    if (Head == NULL) return; 

    Node* Temp = Head;

    do {
        printf("%d ", Temp->data);
        Temp = Temp->next;
    }
    while(Temp != Head);
    printf("\n");
}

Node* rotate(Node* Head, int k)
{
    if (Head == NULL || k <= 0) return Head;

    int length = 0;
    Node* Temp = Head;
    do {
        length++;
        Temp = Temp->next;
    } while (Temp != Head);

    k = k % length;
    if (k == 0) return Head;

    int stepsToMove = length - k;
    
    while (stepsToMove > 0) {
        Head = Head->next;
        stepsToMove--;
    }

    return Head; 
}

int main() {
    
    int k;
    Node* head = NULL;
    
    head = createlist(5, head);

    printf("Original list: ");
    traverse(head);

    printf("By how much do you want to rotate the list? ");
    scanf("%d", &k);

    head = rotate(head, k);

    printf("Rotated list: ");
    traverse(head);

    return 0; 
}