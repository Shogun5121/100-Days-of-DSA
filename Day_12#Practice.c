#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("Symmetry is only checked for square matrices.\n");
        return 0;
    }

    int n = rows;  
    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);


    int isSymmetric = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; 
                break;
            }
        }
        if (!isSymmetric) break; 
    }

    if (isSymmetric)
        printf("Matrix is Symmetrical\n");
    else
        printf("Matrix is Not Symmetrical\n");

    return 0;
}
