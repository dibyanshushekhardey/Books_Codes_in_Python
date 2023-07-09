#include <stdio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
};

// Function to multiply a polynomial with a number
void multiplyPolynomial(struct Term polynomial[], int size, int number) {
    for (int i = 0; i < size; i++) {
        polynomial[i].coefficient *= number;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Term polynomial[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d ", polynomial[i].coefficient, polynomial[i].exponent);
        if (i < size - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the polynomial: ");
    scanf("%d", &size);

    struct Term* polynomial = (struct Term*)malloc(size * sizeof(struct Term));

    printf("Enter the terms of the polynomial:\n");
    for (int i = 0; i < size; i++) {
        printf("Term %d:\n", i + 1);
        printf("Enter coefficient: ");
        scanf("%d", &(polynomial[i].coefficient));
        printf("Enter exponent: ");
        scanf("%d", &(polynomial[i].exponent));
    }

    int number;
    printf("Enter the number to multiply with the polynomial: ");
    scanf("%d", &number);

    printf("Original Polynomial: ");
    displayPolynomial(polynomial, size);

    multiplyPolynomial(polynomial, size, number);

    printf("Polynomial after multiplication: ");
    displayPolynomial(polynomial, size);

    free(polynomial);

    return 0;
}
