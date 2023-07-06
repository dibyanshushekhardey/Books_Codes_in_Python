#include <stdio.h>

float calculateArea(float *base, float *height) {
    return ((*base) * (*height)) / 2.0;
}

int main() {
    float base, height;
    float area;

    printf("Enter the base of the triangle: ");
    scanf("%f", &base);

    printf("Enter the height of the triangle: ");
    scanf("%f", &height);

    area = calculateArea(&base, &height);

    printf("\nThe area of the triangle is: %.2f\n", area);

    return 0;
}
