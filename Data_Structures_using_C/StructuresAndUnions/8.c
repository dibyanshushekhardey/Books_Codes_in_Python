#include <stdio.h>

struct Height {
    int feet;
    int inches;
};

struct Height addHeight(struct Height h1, struct Height h2) {
    struct Height result;

    result.feet = h1.feet + h2.feet;
    result.inches = h1.inches + h2.inches;

    if (result.inches >= 12) {
        result.feet += result.inches / 12;
        result.inches %= 12;
    }

    return result;
}

struct Height subtractHeight(struct Height h1, struct Height h2) {
    struct Height result;

    result.feet = h1.feet - h2.feet;
    result.inches = h1.inches - h2.inches;

    if (result.inches < 0) {
        result.feet -= 1;
        result.inches += 12;
    }

    return result;
}

int main() {
    struct Height height1 = {6, 2};
    struct Height height2 = {5, 4};

    // Adding heights
    struct Height sum = addHeight(height1, height2);
    printf("Sum of heights: %d' %d\"\n", sum.feet, sum.inches);

    // Subtracting heights
    struct Height difference = subtractHeight(height1, height2);
    printf("Difference of heights: %d' %d\"\n", difference.feet, difference.inches);

    return 0;
}
