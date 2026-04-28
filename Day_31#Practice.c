#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    // Read the number of operations
    if (scanf("%d", &n) != 1) return 0;

    // Dynamically allocate the stack array
    // The maximum possible size we need is 'n' (if all operations are pushes)
    int *stack = (int *)malloc(n * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }
    
    int top = -1; // -1 indicates an empty stack

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            // Push operation
            int val;
            scanf("%d", &val);
            // Increment top first, then assign the value
            stack[++top] = val;
        } 
        else if (op == 2) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                // Print the top value, then decrement top
                printf("%d\n", stack[top--]);
            }
        } 
        else if (op == 3) {
            if (top != -1) {
                for (int j = top; j >= 0; j--) {
                    printf("%d", stack[j]);
                    if (j > 0) printf(" ");
                }
            }
            printf("\n");
        }
    }

    // Free the allocated memory to prevent memory leaks
    free(stack);
    return 0;
}