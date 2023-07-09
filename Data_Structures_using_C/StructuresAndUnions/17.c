#include <stdio.h>
#include <string.h>

#define MAX_HOTELS 5

struct Hotel {
    char name[50];
    char address[100];
    int grade;
    int numRooms;
    float roomCharges;
};

void printHotelsByGrade(const struct Hotel hotels[], int numHotels, int targetGrade) {
    printf("Hotels in Grade %d:\n", targetGrade);
    for (int i = 0; i < numHotels; i++) {
        if (hotels[i].grade == targetGrade) {
            printf("%s\n", hotels[i].name);
        }
    }
    printf("\n");
}

void printHotelsByRoomCharges(const struct Hotel hotels[], int numHotels, float maxRoomCharges) {
    printf("Hotels with Room Charges Less than %.2f:\n", maxRoomCharges);
    for (int i = 0; i < numHotels; i++) {
        if (hotels[i].roomCharges < maxRoomCharges) {
            printf("%s\n", hotels[i].name);
        }
    }
    printf("\n");
}

int main() {
    struct Hotel hotels[MAX_HOTELS];

    // Hotel 1
    strcpy(hotels[0].name, "Hotel A");
    strcpy(hotels[0].address, "Address A");
    hotels[0].grade = 3;
    hotels[0].numRooms = 100;
    hotels[0].roomCharges = 150.00;

    // Hotel 2
    strcpy(hotels[1].name, "Hotel B");
    strcpy(hotels[1].address, "Address B");
    hotels[1].grade = 4;
    hotels[1].numRooms = 75;
    hotels[1].roomCharges = 200.00;

    // Hotel 3
    strcpy(hotels[2].name, "Hotel C");
    strcpy(hotels[2].address, "Address C");
    hotels[2].grade = 3;
    hotels[2].numRooms = 50;
    hotels[2].roomCharges = 120.00;

    // Hotel 4
    strcpy(hotels[3].name, "Hotel D");
    strcpy(hotels[3].address, "Address D");
    hotels[3].grade = 5;
    hotels[3].numRooms = 200;
    hotels[3].roomCharges = 250.00;

    // Hotel 5
    strcpy(hotels[4].name, "Hotel E");
    strcpy(hotels[4].address, "Address E");
    hotels[4].grade = 2;
    hotels[4].numRooms = 30;
    hotels[4].roomCharges = 80.00;

    printHotelsByGrade(hotels, MAX_HOTELS, 3);
    printHotelsByRoomCharges(hotels, MAX_HOTELS, 150.00);

    return 0;
}
