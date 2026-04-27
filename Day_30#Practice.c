#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* insertTerm(Node* head, int coeff, int exp) {
    if (coeff == 0) {
        return head;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        return newNode;
    }

    if (head->exp == exp) {
        head->coeff += coeff;
        free(newNode);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }

    if (current->next != NULL && current->next->exp == exp) {
        current->next->coeff += coeff;
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

void printPolynomial(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (temp == head) {
            if (temp->coeff < 0) printf("-");
        } else {
            if (temp->coeff > 0) printf(" + ");
            else printf(" - ");
        }

        int c = abs(temp->coeff);

        if (c != 1 || temp->exp == 0) {
            printf("%d", c);
        }

        if (temp->exp > 0) {
            printf("x");
            if (temp->exp > 1) {
                printf("^%d", temp->exp); 
            }
        }

        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    Node* head = NULL;

    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    printPolynomial(head);

    freeList(head);

    return 0;
}