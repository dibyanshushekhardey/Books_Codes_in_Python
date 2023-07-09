#include <stdio.h>

struct Fraction {
    int numerator;
    int denominator;
};

float fractionToFloat(const struct Fraction* fraction) {
    return (float) fraction->numerator / fraction->denominator;
}

int compareFractions(const struct Fraction* fraction1, const struct Fraction* fraction2) {
    float float1 = fractionToFloat(fraction1);
    float float2 = fractionToFloat(fraction2);

    if (float1 == float2) {
        return 0;
    } else if (float1 < float2) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    struct Fraction fraction1, fraction2;

    // Input fraction1
    printf("Enter fraction 1 (numerator/denominator): ");
    scanf("%d/%d", &fraction1.numerator, &fraction1.denominator);

    // Input fraction2
    printf("Enter fraction 2 (numerator/denominator): ");
    scanf("%d/%d", &fraction2.numerator, &fraction2.denominator);

    // Compare fractions
    int result = compareFractions(&fraction1, &fraction2);

    // Print comparison result
    if (result == 0) {
        printf("The fractions are equal.\n");
    } else if (result < 0) {
        printf("The first fraction is less than the second.\n");
    } else {
        printf("The first fraction is greater than the second.\n");
    }

    return 0;
}
