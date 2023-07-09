#include <stdio.h>

struct Date {
    int year;
};

int isLeapYear(struct Date currentDate) {
    if (currentDate.year % 400 == 0) {
        return 1;
    } else if (currentDate.year % 100 == 0) {
        return 0;
    } else if (currentDate.year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct Date currentDate;

    printf("Enter the current year: ");
    scanf("%d", &currentDate.year);

    if (isLeapYear(currentDate)) {
        printf("%d is a leap year.\n", currentDate.year);
    } else {
        printf("%d is not a leap year.\n", currentDate.year);
    }

    return 0;
}
