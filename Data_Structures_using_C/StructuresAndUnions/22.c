#include <stdio.h>

#define PI 3.14159

enum FigureType {
    CIRCLE,
    RECTANGLE,
    TRIANGLE
};

struct Figure {
    enum FigureType type;
    union {
        struct {
            float radius;
        } circle;

        struct {
            float length;
            float width;
        } rectangle;

        struct {
            float side1;
            float side2;
            float side3;
        } triangle;
    } components;
};

float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

float calculateRectangleArea(float length, float width) {
    return length * width;
}

float calculateTriangleArea(float side1, float side2, float side3) {
    // Using Heron's formula to calculate the area of a triangle
    float semiPerimeter = (side1 + side2 + side3) / 2.0;
    return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}

float calculateArea(const struct Figure* figure) {
    switch (figure->type) {
        case CIRCLE:
            return calculateCircleArea(figure->components.circle.radius);

        case RECTANGLE:
            return calculateRectangleArea(figure->components.rectangle.length, figure->components.rectangle.width);

        case TRIANGLE:
            return calculateTriangleArea(figure->components.triangle.side1, figure->components.triangle.side2, figure->components.triangle.side3);

        default:
            return 0.0;
    }
}

int main() {
    struct Figure figure;

    // Input figure type
    printf("Enter figure type (0 for Circle, 1 for Rectangle, 2 for Triangle): ");
    scanf("%d", &(figure.type));

    // Input figure components
    switch (figure.type) {
        case CIRCLE:
            printf("Enter radius: ");
            scanf("%f", &(figure.components.circle.radius));
            break;

        case RECTANGLE:
            printf("Enter length: ");
            scanf("%f", &(figure.components.rectangle.length));
            printf("Enter width: ");
            scanf("%f", &(figure.components.rectangle.width));
            break;

        case TRIANGLE:
            printf("Enter side 1: ");
            scanf("%f", &(figure.components.triangle.side1));
            printf("Enter side 2: ");
            scanf("%f", &(figure.components.triangle.side2));
            printf("Enter side 3: ");
            scanf("%f", &(figure.components.triangle.side3));
            break;

        default:
            break;
    }

    // Calculate and print the area
    float area = calculateArea(&figure);
    printf("Area: %.2f\n", area);

    return 0;
}
