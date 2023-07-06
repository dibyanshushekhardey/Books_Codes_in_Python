#include <stdio.h>
#include <math.h>

float calculateSimpleInterest(float principal, float rate, int time) {
    return (principal * rate * time) / 100.0;
}

float calculateCompoundInterest(float principal, float rate, int time) {
    return principal * pow((1 + rate / 100.0), time) - principal;
}

int main() {
    float principal, rate;
    int time;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the rate of interest: ");
    scanf("%f", &rate);

    printf("Enter the time period (in years): ");
    scanf("%d", &time);

    float simpleInterest = calculateSimpleInterest(principal, rate, time);
    float compoundInterest = calculateCompoundInterest(principal, rate, time);

    printf("\nSimple Interest: %.2f\n", simpleInterest);
    printf("Compound Interest: %.2f\n", compoundInterest);

    return 0;
}
