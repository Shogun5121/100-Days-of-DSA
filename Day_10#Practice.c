#include <stdio.h>

int main() {
    char s[100];
    int i = 0, j = 0;

    scanf("%s", s);

    // Find length manually
    while (s[j] != '\0') {
        j++;
    }
    j--;  // point to last character

    // Two-pointer comparison
    while (i < j) {
        if (s[i] != s[j]) {
            printf("NO");
            return 0;
        }
        i++;
        j--;
    }

    printf("YES");
    return 0;
}
