#include <stdio.h>
#include <math.h>

int main() {
    float number;
    int rightmostDigit;

    printf("Enter a floating-point number: ");
    scanf("%f", &number);

    // Extract the rightmost digit of the integral part
    rightmostDigit = (int)(fabs(number)) % 10;

    printf("\nRightmost digit of the integral part: %d\n", rightmostDigit);

    return 0;
}
