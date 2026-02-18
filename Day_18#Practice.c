#include <stdio.h>

int main() {

    int n, k, i;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Array Elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter integer k by which u want to rotate the array:\n");
    scanf("%d", &k);
    
    int count = 0;
    int x;
    while(count<k)
    {
        for(i=n-1; i>=0; i--)
        {
            if(i==n-1)
            {
                x = arr[i];
                continue;
            }

            arr[i+1] = arr[i];
        }
        arr[0] = x;
        count++;
    }

    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

}


