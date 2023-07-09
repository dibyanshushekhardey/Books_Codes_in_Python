#include <stdio.h>

struct Time {
    int hr;
    int min;
    int sec;
};

int main() {
    struct Time start_time, end_time;

    // Input start_time
    printf("Enter start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &start_time.hr, &start_time.min, &start_time.sec);

    // Input end_time
    printf("Enter end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &end_time.hr, &end_time.min, &end_time.sec);

    // Continuously display "GOOD DAY" until start_time reaches end_time
    while (start_time.hr < end_time.hr || start_time.min < end_time.min || start_time.sec < end_time.sec) {
        printf("GOOD DAY\n");

        // Increment start_time by 1 second
        start_time.sec++;

        if (start_time.sec >= 60) {
            start_time.sec = 0;
            start_time.min++;
        }

        if (start_time.min >= 60) {
            start_time.min = 0;
            start_time.hr++;
        }
    }

    return 0;
}
