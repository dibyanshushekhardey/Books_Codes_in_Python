#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

double calculateDistance(struct Point p1, struct Point p2) {
    int xDiff = p2.x - p1.x;
    int yDiff = p2.y - p1.y;
    double distance = sqrt(xDiff * xDiff + yDiff * yDiff);
    return distance;
}

int main() {
    struct Point p1 = {6, 3};
    struct Point p2 = {2, 2};

    double distance = calculateDistance(p1, p2);

    printf("Distance between (%d,%d) and (%d,%d) is %.2lf\n", p1.x, p1.y, p2.x, p2.y, distance);

    return 0;
}
