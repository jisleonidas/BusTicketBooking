#include "header.h"
#include "util.h"

void display_buses()
{
    for (int i = 0; i < MAX_BUSES; i++) {
        printf("Bus %d\n", BUSES[i].num);
        printf("Source: %s, Destination: %s\n", BUSES[i].source, BUSES[i].dest);

        printf("Departure Time: ");
        display_datetime(BUSES[i].dep);
        print(", Arrival Time: ");
        display_datetime(BUSES[i].arriv);
        print("\n");

        printf("Available seats: \n");
        display_seats(BUSES[i].seats);
    }
}
