#include "header.h"
#include "func.h"
#include "util.h"
#include "init.h"

int main()
{
    int choice, cont;

    signal(SIGINT, cleanup);

    initialize_bus_data(BUSES, 5);
    // display_buses();

    TICKETS_BOOKED = 0;

    cont = TRUE;
    while (cont) {
        display_menu();
        printf("\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_buses();
                break;
            case 2:
                book_tickets();
                break;
            case 3:
                manage_bookings();
                break;
            case 4:
                cont = FALSE;
                printf("Exiting ...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
}
