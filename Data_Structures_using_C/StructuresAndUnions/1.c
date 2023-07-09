struct Date {
    int day;
    int month;
    int year;
};

struct Marks {
    float english;
    float mathematics;
    float computerScience;
};

struct Name {
    char firstName[50];
    char middleName[50];
    char lastName[50];
};

struct Student {
    int rollNumber;
    struct Name name;
    char sex;
    struct Date dateOfBirth;
    struct Marks marks;
};
