#include <stdio.h>
#include <ctype.h>

int main() {
    char input;

    printf("Enter a number or character: ");
    scanf(" %c", &input);

    if (isdigit(input)) {
        printf("\nInput is a number.\n");
    } else if (isalpha(input)) {
        printf("\nInput is a character.\n");
        printf("ASCII Value: %d\n", input);

        if (islower(input)) {
            printf("Character is in lowercase.\n");
        } else if (isupper(input)) {
            printf("Character is in uppercase.\n");
        }
    } else {
        printf("\nInput is neither a number nor a character.\n");
    }

    return 0;
}
