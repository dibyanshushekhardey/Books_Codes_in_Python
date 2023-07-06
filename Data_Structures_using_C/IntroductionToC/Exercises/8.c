#include <stdio.h>

#define HRA_PERCENTAGE 10
#define TA_PERCENTAGE 5

int main() {
    float basicPay, salary;
    float hra, ta;

    printf("Enter the basic pay: ");
    scanf("%f", &basicPay);

    hra = (HRA_PERCENTAGE * basicPay) / 100.0;
    ta = (TA_PERCENTAGE * basicPay) / 100.0;

    salary = basicPay + hra + ta;

    printf("\nSalary breakdown:\n");
    printf("Basic Pay: %.2f\n", basicPay);
    printf("HRA: %.2f\n", hra);
    printf("TA: %.2f\n", ta);
    printf("Salary: %.2f\n", salary);

    return 0;
}
