#include <stdio.h>

int main() {
    char *message = "Programming in C is Fun";
    char *ptr = message;

    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }

    printf("\n");

    return 0;
}
