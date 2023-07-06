#include <stdio.h>
#include <math.h>

int isArmstrong(int number) {
    int originalNumber, remainder, result = 0;
    int n = 0;

    originalNumber = number;

    while (originalNumber != 0) {
        originalNumber /= 10;
        ++n;
    }

    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }

    if (result == number) {
        return 1; // Armstrong number
    } else {
        return 0; // Not an Armstrong number
    }
}

int main() {
    int number;

    printf("Enter numbers (-1 to stop):\n");

    do {
        scanf("%d", &number);

        if (number != -1) {
            if (isArmstrong(number)) {
                printf("%d is an Armstrong number.\n", number);
            } else {
                printf("%d is not an Armstrong number.\n", number);
            }
        }
    } while (number != -1);

    return 0;
}
