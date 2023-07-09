#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

void initializeEmployee(struct Employee* emp, const char* name, int age, float salary) {
    strcpy(emp->name, name);
    emp->age = age;
    emp->salary = salary;
}

void printEmployee(const struct Employee* emp) {
    printf("Employee Information:\n");
    printf("Name: %s\n", emp->name);
    printf("Age: %d\n", emp->age);
    printf("Salary: %.2f\n", emp->salary);
    printf("\n");
}

int main() {
    struct Employee emp;
    struct Employee* empPtr = &emp;

    initializeEmployee(empPtr, "John Doe", 30, 5000.00);
    printEmployee(empPtr);

    return 0;
}
