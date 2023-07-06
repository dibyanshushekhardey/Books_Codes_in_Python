#include <stdio.h>

int main() {
    int numbers[10];
    int i;

    // Read 10 integers from the user
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Display the numbers with three numbers per line separated by commas
    printf("Numbers entered:\n");
    for (i = 0; i < 10; i++) {
        printf("%d", numbers[i]);

        // Print comma and newline only if it's not the last number in a line
        if ((i + 1) % 3 != 0 && i != 9) {
            printf(", ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
