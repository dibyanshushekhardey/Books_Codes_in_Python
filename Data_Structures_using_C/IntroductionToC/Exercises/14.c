#include <stdio.h>
#include <math.h>

float calculateArea(float base, float height) {
    return (base * height) / 2.0;
}

int main() {
    float base, height;

    printf("Enter the base of the triangle: ");
    scanf("%f", &base);

    printf("Enter the height of the triangle: ");
    scanf("%f", &height);

    float area = calculateArea(base, height);

    printf("\nThe area of the triangle is: %.2f\n", area);

    return 0;
}
