#include <stdio.h>

#define MAX 20  // Maximum size of the matrix

int main() {
    int n, i, j;
    int matrix[MAX][MAX];
    int isIdentity = 1;  // Flag to track if matrix is identity

    // Read size of matrix
    scanf("%d", &n);

    // Read matrix elements
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check for identity matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                // Diagonal element must be 1
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                // Non-diagonal element must be 0
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(!isIdentity)
            break;
    }

    // Print result
    if(isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
