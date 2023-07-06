#include <stdio.h>

int main() {
    char address[100];

    printf("Enter your address: ");
    fgets(address, sizeof(address), stdin);

    printf("\nAddress entered:\n");

    // Break the address into multiple lines
    printf("Line 1: ");
    puts(address);

    printf("Line 2: ");
    puts(address);

    printf("Line 3: ");
    puts(address);

    return 0;
}
