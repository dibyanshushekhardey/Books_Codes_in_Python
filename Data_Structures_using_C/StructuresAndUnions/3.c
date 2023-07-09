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
        float averageMarks = totalMarks / 3.0f;

        if (averageMarks >= 80) {
            students[i].grade = 'A';
        } else if (averageMarks >= 60) {
            students[i].grade = 'B';
        } else if (averageMarks >= 40) {
            students[i].grade = 'C';
        } else {
            students[i].grade = 'F';
        }
    }

    // Calculate class average
    int classTotalMarks = 0;
    for (int i = 0; i < 5; i++) {
        int totalMarks = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        classTotalMarks += totalMarks;
    }
    float classAverage = classTotalMarks / (3.0f * 5);

    // Display details of each student along with their average marks
    printf("\nStudent Details:\n");
    for (int i = 0; i < 5; i++) {
        int totalMarks = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        float averageMarks = totalMarks / 3.0f;

        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d %d %d\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("Average Marks: %.2f\n", averageMarks);
        printf("Grade: %c\n", students[i].grade);
    }

    // Display class average
    printf("\nClass Average: %.2f\n", classAverage);

    return 0;
}
