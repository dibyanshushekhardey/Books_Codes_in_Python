#include <stdio.h>

struct Point {
    int x;
    int y;
};

int determineQuadrant(const struct Point* point) {
    if (point->x > 0 && point->y > 0) {
        return 1;
    } else if (point->x < 0 && point->y > 0) {
        return 2;
    } else if (point->x < 0 && point->y < 0) {
        return 3;
    } else if (point->x > 0 && point->y < 0) {
        return 4;
    } else {
        return 0;
    }
}

int main() {
    struct Point point;

    // Input point coordinates
    printf("Enter the x-coordinate: ");
    scanf("%d", &(point.x));

    printf("Enter the y-coordinate: ");
    scanf("%d", &(point.y));

    // Determine the quadrant
    int quadrant = determineQuadrant(&point);

    // Print the quadrant
    if (quadrant == 0) {
        printf("The point lies on the origin.\n");
    } else {
        printf("The point lies in Quadrant %d.\n", quadrant);
    }

    return 0;
}
