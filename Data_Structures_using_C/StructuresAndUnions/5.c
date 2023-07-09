#include <stdio.h>

struct Numbers {
    int num1;
    int num2;
    int num3;
};

int findSmallest(struct Numbers nums) {
    int smallest = nums.num1;
    if (nums.num2 < smallest) {
        smallest = nums.num2;
    }
    if (nums.num3 < smallest) {
        smallest = nums.num3;
    }
    return smallest;
}

int main() {
    struct Numbers nums;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &nums.num1, &nums.num2, &nums.num3);

    int smallest = findSmallest(nums);

    printf("The smallest number is: %d\n", smallest);

    return 0;
}
