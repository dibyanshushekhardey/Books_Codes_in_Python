#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks[3];
    char grade;
};

int main() {
    struct Student students[5]; // Assuming there are 5 students

    // Input student details
    for (int i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter marks for three subjects (separated by spaces) for student %d: ", i + 1);
        scanf("%d %d %d", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
        getchar(); // Consume the newline character

        int totalMarks = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        float aggregate = totalMarks / 3.0f;

        if (aggregate >= 80) {
            students[i].grade = 'A';
        } else if (aggregate >= 60) {
            students[i].grade = 'B';
        } else if (aggregate >= 40) {
            students[i].grade = 'C';
        } else {
            students[i].grade = 'F';
        }
    }

    // Display details of a student entered by the user
    char searchName[50];
    printf("Enter the name of the student to display details: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove trailing newline character

    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\nStudent Details:\n");
            printf("Name: %s\n", students[i].name);
            printf("Marks: %d %d %d\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
            printf("Grade: %c\n", students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }

    // Display names of students with less than 40% aggregate
    printf("\nStudents with less than 40%% aggregate:\n");
    for (int i = 0; i < 5; i++) {
        int totalMarks = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        float aggregate = totalMarks / 3.0f;

        if (aggregate < 40) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}
