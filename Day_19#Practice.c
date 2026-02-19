#include <stdio.h>

int modulus(int x) {
    if(x<0)
    {
        x = x*-1;
    }
    if(x>=0)
    {
        x = x*1;
    }

    return x;
}

int main() {
    int n, i, j;

    while(1)
    {
        printf("Enter the number of elements for array:\n");
        scanf("%d", &n);

        if(n<2)
        {
            printf("Error: Need atleast 2 elements for a sum.");
            continue;
        }

        break;
    }

    int arr[n];

    printf("Enter array elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int Minimum;
    int mod;
    int E1, E2;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n;j++)
        {
            sum = arr[i] + arr[j];

            if (sum==0)
            {
                continue;
            }

            mod = modulus(sum);

            if(i==0 && j==1)
            {
                Minimum = mod;
                E1 = i;
                E2 = j;
            }
            else
            {
                if(mod<Minimum)
                {
                    Minimum = mod;
                    E1 = i;
                    E2 = j;
                }
            }
        }
    }

    printf("\nElements %d and %d have a sum thats closest to zero which is %d", arr[E1], arr[E2], Minimum);

    return 0;
}