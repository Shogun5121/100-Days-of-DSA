#include <stdio.h>

int fibonacci(int n) {
    if (n==0) {
        return 0;
    }

    if (n==1) {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;

    printf("Enter n for which u want to calculate the nth fibonacci number: ");
    scanf("%d", &n);

    int x = fibonacci(n);

    printf("%d", x);
    
    return 0;
}