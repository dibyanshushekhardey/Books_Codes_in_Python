#include <stdio.h>

int isDivisibleByTwo(int number) {
    if (number % 2 == 0) {
        return 1; // Divisible by 2
    } else {
        return 0; // Not divisible by 2
    }
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int result = isDivisibleByTwo(number);

    if (result == 1) {
        printf("\nThe number is divisible by 2.\n");
    } else {
        printf("\nThe number is not divisible by 2.\n");
    }

    return 0;
}
