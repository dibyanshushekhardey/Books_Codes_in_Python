#include <stdio.h>

int main() {
    char items[100][100];
    int quantities[100];
    float prices[100];
    int numItems;
    float totalAmount = 0.0;
    int i;

    printf("Enter the number of items purchased: ");
    scanf("%d", &numItems);

    printf("\nEnter the details of each item:\n");
    for (i = 0; i < numItems; i++) {
        printf("Item %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", items[i]);

        printf("Quantity: ");
        scanf("%d", &quantities[i]);

        printf("Price per unit: ");
        scanf("%f", &prices[i]);

        totalAmount += quantities[i] * prices[i];
    }

    printf("\n************ B I L L ************\n");
    printf("Item\t\tQuantity\tPrice\t\tAmount\n");
    printf("--------------------------------------------\n");
    for (i = 0; i < numItems; i++) {
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", items[i], quantities[i], prices[i], quantities[i] * prices[i]);
    }
    printf("--------------------------------------------\n");
    printf("Total Amount to be paid: %.2f\n", totalAmount);

    return 0;
}
