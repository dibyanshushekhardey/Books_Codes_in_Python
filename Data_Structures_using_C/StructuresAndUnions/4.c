#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Marks {
    float english;
    float mathematics;
    float computerScience;
};

struct Name {
    char firstName[50];
    char middleName[50];
    char lastName[50];
};

struct Student {
    int rollNumber;
    struct Name name;
    char sex;
    struct Date dateOfBirth;
    struct Marks marks;
};

int main() {
    struct Student students[5]; // Assuming there are 5 students

    // Input student details
    for (int i = 0; i < 5; i++) {
        printf("Enter Roll Number of student %d: ", i + 1);
        scanf("%d", &students[i].rollNumber);
        getchar(); // Consume the newline character

        printf("Enter First Name of student %d: ", i + 1);
        fgets(students[i].name.firstName, sizeof(students[i].name.firstName), stdin);
        students[i].name.firstName[strcspn(students[i].name.firstName, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Middle Name of student %d: ", i + 1);
        fgets(students[i].name.middleName, sizeof(students[i].name.middleName), stdin);
        students[i].name.middleName[strcspn(students[i].name.middleName, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Last Name of student %d: ", i + 1);
        fgets(students[i].name.lastName, sizeof(students[i].name.lastName), stdin);
        students[i].name.lastName[strcspn(students[i].name.lastName, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Sex (M/F) of student %d: ", i + 1);
        scanf("%c", &students[i].sex);
        getchar(); // Consume the newline character

        printf("Enter Date of Birth (DD MM YYYY) of student %d: ", i + 1);
        scanf("%d %d %d", &students[i].dateOfBirth.day, &students[i].dateOfBirth.month, &students[i].dateOfBirth.year);
        getchar(); // Consume the newline character

        printf("Enter Marks in English, Mathematics, and Computer Science (separated by spaces) for student %d: ", i + 1);
        scanf("%f %f %f", &students[i].marks.english, &students[i].marks.mathematics, &students[i].marks.computerScience);
        getchar(); // Consume the newline character
    }

    // Display details of the student with the given Date of Birth
    struct Date searchDate;
    printf("Enter the Date of Birth (DD MM YYYY) to display details: ");
    scanf("%d %d %d", &searchDate.day, &searchDate.month, &searchDate.year);
    getchar(); // Consume the newline character

    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].dateOfBirth.day == searchDate.day && students[i].dateOfBirth.month == searchDate.month &&
            students[i].dateOfBirth.year == searchDate.year) {
            printf("\nStudent Details:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s %s %s\n", students[i].name.firstName, students[i].name.middleName, students[i].name.lastName);
            printf("Sex: %c\n", students[i].sex);
            printf("Date of Birth: %d-%02d-%02d\n", students[i].dateOfBirth.year, students[i].dateOfBirth.month, students[i].dateOfBirth.day);
            printf("Marks: English=%.2f, Mathematics=%.2f, Computer Science=%.2f\n", students[i].marks.english, students[i].marks.mathematics, students[i].marks.computerScience);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }

    return 0;
}
