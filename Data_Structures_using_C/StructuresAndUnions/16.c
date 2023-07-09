#include <stdio.h>

struct Vector {
    int x;
    int y;
    int z;
};

void readVector(struct Vector* v) {
    printf("Enter the x-coordinate: ");
    scanf("%d", &(v->x));

    printf("Enter the y-coordinate: ");
    scanf("%d", &(v->y));

    printf("Enter the z-coordinate: ");
    scanf("%d", &(v->z));
}

void printVector(const struct Vector* v) {
    printf("Vector: (%d, %d, %d)\n", v->x, v->y, v->z);
}

struct Vector addVectors(const struct Vector* v1, const struct Vector* v2) {
    struct Vector result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    result.z = v1->z + v2->z;
    return result;
}

void scaleVector(struct Vector* v, int factor) {
    v->x *= factor;
    v->y *= factor;
    v->z *= factor;
}

int main() {
    struct Vector vector1, vector2;

    printf("Enter data for Vector 1:\n");
    readVector(&vector1);

    printf("Enter data for Vector 2:\n");
    readVector(&vector2);

    printf("Vector 1:\n");
    printVector(&vector1);

    printf("Vector 2:\n");
    printVector(&vector2);

    struct Vector sum = addVectors(&vector1, &vector2);
    printf("Sum of vectors:\n");
    printVector(&sum);

    printf("Scaling Vector 1 by a factor of 10:\n");
    scaleVector(&vector1, 10);
    printVector(&vector1);

    return 0;
}
