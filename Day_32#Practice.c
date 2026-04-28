#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    
    int *stack = (int *)malloc(n * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }
    
    scanf("%d", &m);
    
    int top = n - m - 1;
    
    if (top < -1) {
        top = -1;
    }
    
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    
    free(stack);
    return 0;
}