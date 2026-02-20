//Uses the concept of a running sum 
//sum of anything between two running sums that are equal is zero since there has been no net increment/decrement in the running sum

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    long long prefix[n];
    long long sum = 0;
    long long count = 0;

    for(int i=0;i<n;i++) {
        sum += arr[i];
        prefix[i] = sum;

        if(sum == 0)
            count++;

        for(int j=0;j<i;j++) {
            if(prefix[j] == sum)
                count++;
        }
    }

    printf("%lld\n", count);
    return 0;
}