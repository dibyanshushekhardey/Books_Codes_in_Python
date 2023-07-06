#include <stdio.h>

int main() {
    float num1, num2, num3;
    float sum;

    printf("Enter three floating-point numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    sum = num1 + num2 + num3;

    printf("\nSum: %.2f\n", sum);

    return 0;
}
