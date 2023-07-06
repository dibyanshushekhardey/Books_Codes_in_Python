#include <stdio.h>
#include <math.h>

int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int m, n;

    printf("Enter the starting number (m): ");
    scanf("%d", &m);

    printf("Enter the ending number (n): ");
    scanf("%d", &n);

    printf("\nPrime numbers from %d to %d:\n", m, n);

    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}


