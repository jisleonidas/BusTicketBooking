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
    printf("----------------\n");
    printf("Chair    Sleeper\n");
    printf("----------------\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i])
            printf("   ");
        else
            printf("%2d ", i+1);

        if ((i+1) % 4 == 0)
            printf("\n");
        else if ((i+1) % 2 == 0)
            printf(" |  ");
    }
    printf("----------------\n");
}

int count_free_seats(Bus *bus)
{
    int i, count;

    for (i = 0; i < MAX_SEATS; i++)
        if (bus->seats[i])
            count++;
    
    return count;
}

/*
 * base_fare: Base fare for route.
 * count_c: no. of chair (seater) tickets
 * count_s: no. of sleeper tickets
 */
float calculate_fare(float base_fare, int count_c, int count_s)
{
    return base_fare*(count_c+1.5*count_s);
}

void display_booking(Ticket* ticket_ptr)
{
    Passenger pass;

    printf("Booking Number: %d\n", ticket_ptr->booking_num);
    printf("Bus Number: %d\n", ticket_ptr->bus_num);
    printf("Passengers Count: %d\n", ticket_ptr->passengers_num);
    for (int i = 0; i < ticket_ptr->passengers_num; i++) {
        pass = ticket_ptr->passengers[i];
        printf("Passenger %d\n", i+1);
        printf("Name: %s\n", pass.name);
        printf("Age: %d\n", pass.age);
    }
    printf("Seats selected: ");
    for (int i = 0; i < ticket_ptr->passengers_num; i++) {
        printf("%d ", ticket_ptr->seats[i]);
    }
    printf("\n");
    printf("Total fare: %.2f\n", ticket_ptr->total_fare);
}

void display_bookings()
{
    for (int i = 0; i < TICKETS_BOOKED; i++) {
        display_booking(&TICKETS[i]);
        printf("\n");
    }
}

void convert_lowercase(char a[MAX_STR_LEN])
{
    for (int i = 0; i < MAX_STR_LEN && a[i] != '\0'; i++) {
        if (65 <= a[i] && a[i] <= 90)
            a[i] += 32;  // Convert to lowercase character.
    }
}

int compare_string(char a[MAX_STR_LEN], char b[MAX_STR_LEN])
{
    char a_copy[MAX_STR_LEN], b_copy[MAX_STR_LEN];
    strcpy(a_copy, a);
    strcpy(b_copy, b);
    convert_lowercase(a_copy);
    convert_lowercase(b_copy);

    return strcmp(a_copy, b_copy);
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

void cleanup(int signal)
{
    Ticket *ticket_ptr;

    for (int i = 0; i < TICKETS_BOOKED; i++) {
        if (ticket_ptr != NULL) {
            ticket_ptr = &TICKETS[TICKETS_BOOKED];
            free(ticket_ptr->passengers);
            free(ticket_ptr->seats);
        }
    }
    printf("\nMemory freed.\n");
    exit(signal);
}