#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    int count = 0;
    int i;

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        char currentChar = tolower(text[i]);
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
            count++;
        }
    }

    printf("Number of vowels in the text: %d\n", count);

    return 0;
}
