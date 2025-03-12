#include "header.h"

void display_menu()
{
    printf(
        "MENU\n"
        "----\n"
        "1. View buses\n"
        "2. Book tickets\n"
        "3. Manage bookings\n"
    );
}

void slice(char* result, char *str, size_t start, size_t end) {
    strncpy(result, str+start, end-start);
    result[end-start] = '\0';
}

void parse_datetime(char string[], char datetime[])
{
    int day, month, year, hour, minute;

    sscanf(datetime, "%2d%2d%4d%2d%2d", &day, &month, &year, &hour, &minute);
    sprintf(string, "%02d/%02d/%04d %02d:%02d", day, month, year, hour, minute);
}

void display_datetime(char datetime[])
{
    char string[20];

    parse_datetime(string, datetime);
    printf("%s", string);
}

void display_seats(int seats[])
{
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i])
            printf("   ");
        else
            printf("%2d ", i+1);

        if (i % 2 != 0)
            printf("\n");
    }
}

int count_free_seats(Bus *bus)
{
    int i, count;

    for (i = 0; i < MAX_SEATS; i++)
        if (bus->seats[i])
            count++;
    
    return count;
}

int usergetline(char buf[MAX_STR_LEN])
{
    int i, c;

    for (i = 0; i < MAX_STR_LEN-1 && (c=getchar()) != '\n' && c != EOF; i++) {
        buf[i] = c;
    }
    if (c == '\n' || c == EOF)
        buf[i] = '\0';
    
    return i;
}

void skipgarb()
{
    int c;

    while ((c=getchar()) != '\n' && c != EOF)
        ;
}
