#include <stdio.h>

int main() {
    int m, n;

    printf("Enter the starting number (m): ");
    scanf("%d", &m);

    printf("Enter the ending number (n): ");
    scanf("%d", &n);

    printf("\nOdd numbers from %d to %d:\n", m, n);

    // Ensure m is odd
    if (m % 2 == 0) {
        m++;
    }

    // Print odd numbers from m to n
    for (int i = m; i <= n; i += 2) {
        printf("%d\n", i);
    }

    return 0;
}
