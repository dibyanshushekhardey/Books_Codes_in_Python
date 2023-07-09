#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isValidDate(struct Date date) {
    // Check if the month is valid
    if (date.month < 1 || date.month > 12) {
        return 0;
    }

    // Check if the day is valid
    int maxDays = 31;

    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        maxDays = 30;
    } else if (date.month == 2) {
        if (isLeapYear(date.year)) {
            maxDays = 29;
        } else {
            maxDays = 28;
        }
    }

    if (date.day < 1 || date.day > maxDays) {
        return 0;
    }

    // Check if the year is valid
    if (date.year < 1) {
        return 0;
    }

    return 1;
}

void incrementDate(struct Date* date, int days) {
    for (int i = 0; i < days; i++) {
        date->day++;
        int maxDays = 31;

        if (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11) {
            maxDays = 30;
        } else if (date->month == 2) {
            if (isLeapYear(date->year)) {
                maxDays = 29;
            } else {
                maxDays = 28;
            }
        }

        if (date->day > maxDays) {
            date->day = 1;
            date->month++;

            if (date->month > 12) {
                date->month = 1;
                date->year++;
            }
        }
    }
}

void printDate(struct Date date) {
    printf("Date: %02d-%02d-%04d\n", date.day, date.month, date.year);
}

int main() {
    struct Date date;
    int numDays;

    // Read date and number of days from the user
    printf("Enter the date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);

    printf("Enter the number of days to add: ");
    scanf("%d", &numDays);

    // Validate the date
    if (isValidDate(date)) {
        printf("Original Date:\n");
        printDate(date);

        // Increment the date
        incrementDate(&date, numDays);

        printf("New Date:\n");
        printDate(date);
    } else {
        printf("Invalid date!\n");
    }

    return 0;
}
