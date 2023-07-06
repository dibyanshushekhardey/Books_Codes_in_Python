#include <stdio.h>

int main() {
    int n;
    int sum = 0;
    float average;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    average = (float) sum / n;

    printf("\nSum of numbers from 1 to %d: %d\n", n, sum);
    printf("Average of numbers from 1 to %d: %.2f\n", n, average);

    return 0;
}
