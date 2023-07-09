#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;

    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes + (result.seconds / 60);
    result.hours = t1.hours + t2.hours + (result.minutes / 60);

    result.seconds %= 60;
    result.minutes %= 60;

    return result;
}

struct Time subtractTime(struct Time t1, struct Time t2) {
    struct Time result;

    result.seconds = t1.seconds - t2.seconds;
    result.minutes = t1.minutes - t2.minutes + (result.seconds / 60);
    result.hours = t1.hours - t2.hours + (result.minutes / 60);

    result.seconds = (result.seconds + 60) % 60;
    result.minutes = (result.minutes + 60) % 60;
    result.hours = (result.hours + 24) % 24;

    return result;
}

int main() {
    struct Time time1 = {10, 20, 50};
    struct Time time2 = {5, 30, 40};

    // Adding time
    struct Time sum = addTime(time1, time2);
    printf("Sum of time: %dh %dm %ds\n", sum.hours, sum.minutes, sum.seconds);

    // Subtracting time
    struct Time difference = subtractTime(time1, time2);
    printf("Difference of time: %dh %dm %ds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
