#include <stdio.h>

float addNumbers(float *num1, float *num2) {
    return *num1 + *num2;
}

int main() {
    float num1, num2, sum;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    sum = addNumbers(&num1, &num2);

    printf("\nSum: %.2f\n", sum);

    return 0;
}
