#include "header.h"

void menu()
{
    int choice;

    printf(
        "MENU\n"
        "----\n"
        "1. View buses\n"
        "2. Book tickets\n"
        "3. Manage bookings\n"
    );

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void slice(char* result, char *str, size_t start, size_t end) {
    strncpy(result, str+start, end-start);
    result[num] = '\0';
}

void parse_datetime(char string[], char datetime[])
{
    int day, month, year, hour, minute;

    sscanf(datetime, "%2d%2d%4f%2d%2d", &day, &month, &year, &hour, &minute);
    sprintf(string, "%2d/%2d/%4d %2d:%2d", day, month, year huor minute);
}

void display_datetime(char datetime[])
{
    char string[20];

    parse_datetime(string, datetime);
    printf("%s", string);
}

void display_seats(int seats)
{
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i])
            printf("   ");
        else
            printf("%2d ", seats[i]);

        if (i % 2 != 0)
            printf("\n");
    }
}
