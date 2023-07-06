#include <stdio.h>

int main() {
    float number;

    printf("Enter a floating-point value: ");
    scanf("%f", &number);

    printf("\nExponential format (2 decimal places): %.2e\n", number);
    printf("Exponential format (4 decimal places): %.4e\n", number);
    printf("Exponential format (8 decimal places): %.8e\n", number);

    return 0;
}
