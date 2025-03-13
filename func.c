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

void search_bus()
{
    int matches[MAX_BUSES] = {1, 1, 1, 1, 1};
    int match_source, match_dest, match_dep;
    char source[MAX_STR_LEN], dest[MAX_STR_LEN], dep[13];

    match_source = match_dest = match_dep = 0;

    print_header("BUS SEARCH");
    printf("(Tip: Leave a field blank to not filter by it)\n\n");
    printf("Source: ");
    usergetline(source);
    printf("Destination: ");
    usergetline(dest);
    printf("Departure time: ");
    usergetline(dep);

    // Match by field if not empty.
    match_source = !is_whitespace(source);
    match_dest = !is_whitespace(dest);
    match_dep = !is_whitespace(dep);

    print_header("MATCHES FOUND");
    for (int i = 0; i < MAX_BUSES; i++) {
        if (match_source) {
            if (compare_string(source, BUSES[i].source) != 0)
                matches[i] = 0;
        }
        if (match_dest) {
            if (compare_string(dest, BUSES[i].dest) != 0)
                matches[i] = 0;
        }
        if (match_dep) {
            if (compare_string(dep, BUSES[i].dep) != 0)
                matches[i] = 0;
        }

        if (matches[i]) {
            display_bus(BUSES[i]);
        }
    }
}

void display_buses()
{
    int choice;

    printf("DISPLAY BUSES\n");
    printf("-------------\n");
    printf("1. Display All Buses\n");
    printf("2. Search Buses.\n\n");
    
    printf("Enter choice: ");
    scanf("%d", &choice);
    skipgarb();

    switch (choice) {
        case 1:
            for (int i = 0; i < MAX_BUSES; i++) {
                display_bus(BUSES[i]);
                printf("\n");
            }
            break;
        case 2:
            search_bus();
    }
}

void book_tickets()
{
    int i, num, bus_num, seat_num, count_c, count_s;
    float total_fare;
    char c, name[MAX_STR_LEN];
    Bus *bus_ptr = NULL;
    Ticket *ticket_ptr = NULL;

    printf("Enter bus number: ");
    scanf("%d", &bus_num);

    printf("\n");
    for (int i = 0; i < MAX_BUSES; i++) {
        if (BUSES[i].num == bus_num) {
            printf("Bus found!\n");
            display_bus(BUSES[i]);
            bus_ptr = &BUSES[i];
        }
    }
    if (bus_ptr == NULL) {
        printf("Bus not found!\n");
        return;
    }
    printf("\n");

    printf("Enter no. of passengers: ");
    scanf("%d", &num);
    skipgarb();

    if (count_free_seats(bus_ptr) < num) {
        printf("Enough seats not available on bus %d!\n", bus_num);
        return;
    }

    int* seats = malloc(num * sizeof(int));
    Passenger* passengers = (Passenger *) malloc(num * sizeof(Passenger));


    count_c = count_s = 0;
    printf("Select seats:\n");
    for (i = 0; i < num; i++) {
        printf("Seat %d: ", i+1);
        scanf("%d", &seat_num);
        skipgarb();

        if (!(bus_ptr->seats[seat_num-1])) {
            printf("Seat unavailable! Choose again.\n");
            i--;
            continue;
        }

        seats[i] = seat_num;

        // Count no. of chair and sleeper seats.
        if (seat_num % 4 == 1 || seat_num == 2)
            count_c++;
        else if (seat_num % 4 == 3 || seat_num == 0)
            count_s++;
    }
    printf("\n");

    // printf("Seat Preference Indication:\n");
    // printf("Chair    c\n");
    // printf("Sleeper  s\n");

    printf("Enter Passenger details:\n");
    for (int i = 0; i < num; i++) {
        printf("Passenger %d\n", i+1);

        printf("Enter name: ");
        usergetline(passengers[i].name);

        printf("Enter age: ");
        scanf("%d", &passengers[i].age);
        skipgarb();

        // printf("Enter Seat pref: ");
        // scanf("%c", &passengers[i].pref);
        // skipgarb();

        printf("\n");
    }

    total_fare = calculate_fare(bus_ptr->base_fare, count_c, count_s);    
    printf("Total fare: Rs. %.2f\n", total_fare);

    while (TRUE) {
        printf("Confirm booking? (y/n) ");
        scanf("%c", &c);
        skipgarb();

        if (c == 'y') {
            printf("Booking confirmed!\n");
            break;
        }
        else if (c == 'n') {
            printf("Booking aborted!\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    ticket_ptr = &TICKETS[TICKETS_BOOKED];

    ticket_ptr->bus_num = bus_num;
    ticket_ptr->booking_num = 300+TICKETS_BOOKED;
    ticket_ptr->passengers_num = num;
    ticket_ptr->passengers = passengers;
    ticket_ptr->seats = seats;
    ticket_ptr->total_fare = total_fare;

    for (i = 0; i < num; i++)
        bus_ptr->seats[seats[i]-1] = 0;

    TICKETS_BOOKED++;
}

void manage_bookings()
{
    int choice;

    printf(
        "\n"
        "MANAGE BOOKINGS\n"
        "---------------\n"
        "1. Display all bookings.\n"
        "\n"
    );

    printf("Enter choice: ");
    scanf("%d", &choice);
    skipgarb();

    switch (choice) {
        case 1:
            display_bookings();
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}
