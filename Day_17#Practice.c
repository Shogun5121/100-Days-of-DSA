#include <stdio.h>

int main() {
    int n, i, Maximum, Minimum;

    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter Array Elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if(n%2==0)
    {
        if(arr[0]>arr[1])
        {
            Maximum = arr[0];
            Minimum = arr[1];
        }
        else
        {
            Maximum = arr[1];
            Minimum = arr[0];
        }
    
        i = 2;
    }
    else
    {
        Maximum = Minimum = arr[0];
        i = 1;
    }

    while(i<n-1)
    {
        if(arr[i]>arr[i+1])
        {
            if(arr[i]>Maximum)
            {
                Maximum = arr[i];
            }
            if(arr[i+1]<Minimum)
            {
                Minimum = arr[i+1];
            }
        }
        else
        {
            if(arr[i+1]>Maximum)
            {
                Maximum = arr[i+1];
            }
            if(arr[i]<Minimum)
            {
                Minimum = arr[i];
            }
        }

        i++;
    }

    printf("\nMax: %d\nMin: %d", Maximum, Minimum);
    
}