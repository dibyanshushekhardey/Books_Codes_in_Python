#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    do {
        printf("Enter a character (* to exit): ");
        scanf(" %c", &ch);

        printf("\nCharacter: %c\n", ch);
        printf("ASCII Value: %d\n", ch);

        if (islower(ch)) {
            printf("Uppercase: %c\n", toupper(ch));
        } else if (isupper(ch)) {
            printf("Lowercase: %c\n", tolower(ch));
        }

        printf("---------------------------------------\n");
    } while (ch != '*');

    return 0;
}
