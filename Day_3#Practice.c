#include <stdio.h>

int main() {

    int i, n, k;

    printf("Enter Array Size:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Array Element: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter Key: ");
    scanf("%d", &k);

    int comparison = 0; 
    int Found = 0;

    for(i=0; i<n; i++)
    {
        comparison++;

        if (arr[i] == k)
        {
            Found = 1;
            break;
        }
    }

    if (Found == 1)
    {
        printf("Found at index %d\nComparisons = %d", i, comparison);
    }
    else if (Found == 0)
    {
        printf("Not Found");
    }
}