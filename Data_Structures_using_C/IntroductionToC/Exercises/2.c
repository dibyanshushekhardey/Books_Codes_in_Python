#include <stdio.h>

int main() {
    int count = 0;  // To store the count of even numbers
    int sum = 0;    // To store the sum of even numbers
    int number;

    for (number = 1; number <= 200; number++) {
        if (number % 2 == 0) {
            count++;
            sum += number;
        }
    }

    printf("Count of even numbers between 1 and 200: %d\n", count);
    printf("Sum of even numbers between 1 and 200: %d\n", sum);

    return 0;
}
