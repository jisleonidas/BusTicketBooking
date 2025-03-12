#include "header.h"
#include "util.h"

void display_bus(Bus bus)
{
    printf("Bus %d\n", bus.num);
    printf("Source: %s, Destination: %s\n", bus.source, bus.dest);

    printf("Departure Time: ");
    display_datetime(bus.dep);
    printf(", Arrival Time: ");
    display_datetime(bus.arriv);
    printf("\n");

    printf("Available seats: \n");
    display_seats(bus.seats);
}

void display_buses()
{
    for (int i = 0; i < MAX_BUSES; i++) {
        display_bus(BUSES[i]);
        printf("\n");
    }
}

void book_tickets()
{
    int i, num, bus_num;
    char c, name[MAX_STR_LEN];
    Bus *bus_ptr = NULL;

    printf("Enter bus number: ");
    scanf("%d", &bus_num);

    for (int i = 0; i < MAX_BUSES; i++) {
        if (BUSES[i].num == bus_num) {
            printf("Bus found!\n");
            display_bus(BUSES[i]);
            bus_ptr = &BUSES[i];
        }
    }
    if (bus_ptr == NULL) {
        printf("BUs not found!\n");
        return;
    }

    printf("Enter no. of passengers: ");
    scanf("%d", &num);
    skipgarb();

    if (count_free_seats(bus_ptr) < num) {
        printf("Enough seats not available on bus %d!\n", bus_num);
        return;
    }

    int* seats = malloc(num * sizeof(int));
    Passenger* passengers = (Passenger *) malloc(num * sizeof(Passenger));


    printf("Select seats:\n");
    for (int i = 0; i < num; i++) {
        printf("Seat %d: ", i+1);
        scanf("%d", &seats[i]);
        skipgarb();
    }

    printf("Seat Preference Indication:\n");
    printf("Chair    c\n");
    printf("Sleeper  s\n");

    for (int i = 0; i < num; i++) {
        printf("Passenger %d\n", i+1);

        printf("Enter name: ");
        usergetline(passengers[i].name);

        printf("Enter age: ");
        scanf("%d", &passengers[i].age);
        skipgarb();

        printf("Enter Seat pref: ");
        scanf("%c", &passengers[i].pref);
        skipgarb();

        printf("\n");
    }

    TICKETS[TICKETS_BOOKED].passengers = passengers;
    for (i = 0; i < num; i++)
        bus_ptr->seats[seats[i]-1] = 0;
}
