#include <stdio.h>

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("\nDecimal: %d\n", number);
    printf("Octal: %o\n", number);
    printf("Hexadecimal: %X\n", number);

    return 0;
}
