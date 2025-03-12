#include "header.h"
#include "func.h"
#include "util.h"
#include "init.h"

int main()
{
    int choice;

    initialize_bus_data(BUSES, 5);
    // display_buses();

    TICKETS_BOOKED = 0;

    while (TRUE) {
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
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
}
