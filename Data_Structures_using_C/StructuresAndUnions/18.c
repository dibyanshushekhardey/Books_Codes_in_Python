#include <stdio.h>

union Data {
    int x;
    char y;
    float z;
};

struct DataStruct {
    int x;
    char y;
    float z;
};

int main() {
    union Data dataUnion;
    struct DataStruct dataStruct;

    printf("Size of union: %lu bytes\n", sizeof(dataUnion));
    printf("Size of structure: %lu bytes\n", sizeof(dataStruct));

    return 0;
}
