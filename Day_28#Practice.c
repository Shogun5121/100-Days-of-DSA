#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createlist(int n, Node* head)
{

    Node* newnode = (Node*)malloc(sizeof(Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
    }

    if (n == 1)
    {
        newnode->next = head;
        return newnode;
    }

    newnode->next = createlist(n - 1, head);
    return newnode;
}

void traverse(Node* head)
{
    if (head == NULL) return;

    Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Node* head = NULL;

    head = createlist(5, head);

    traverse(head);

    return 0;
}