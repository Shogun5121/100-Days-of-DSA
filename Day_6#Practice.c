#include <stdio.h>

int main() {

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    int Flag = 0;
    
    while(1) {
        printf("Enter Array Elements: ");
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        

        if(arr[0] > arr[1])
        {
            for(int i=1; i<n-1; i++)
            {
                if (arr[i] < arr[i+1])
                {
                    Flag = 1;
                    break;
                }
            }
        }
        else if(arr[0] < arr[1])
        {
            for(int i=1; i<n-1; i++)
            {
                if (arr[i] > arr[i+1])
                {
                    Flag = 1;
                    break;
                }
            }
        
        }

        if(Flag == 1)
        {
            printf("Please Enter Sorted values\n");
            continue;
        }

        break;
    }

    printf("\n");
    
    for(int i=0; i<n-1; i++)
    {
        if (arr[i] == arr[i+1])
        {
            for(int j = i; j<n-1; j++)
            {
                arr[j] = arr[j+1];
            }
            n--; 
            i--;
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}