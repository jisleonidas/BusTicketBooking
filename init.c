#include "header.h"

void initialize_bus_data(struct Bus buses[], int size) {
    // Bus 1: Chennai to Bangalore
    buses[0].num = 1001;
    strcpy(buses[0].source, "Chennai");
    strcpy(buses[0].dest, "Bangalore");
    strcpy(buses[0].dep, "251020231400"); // 25th October 2023, 14:00
    strcpy(buses[0].arriv, "251020232200"); // 25th October 2023, 22:00
    for (int i = 0; i < MAX_SEATS; i++) buses[0].seats[i] = 1; // All seats available

    // Bus 2: Chennai to Coimbatore
    buses[1].num = 1002;
    strcpy(buses[1].source, "Chennai");
    strcpy(buses[1].dest, "Coimbatore");
    strcpy(buses[1].dep, "251020231500"); // 25th October 2023, 15:00
    strcpy(buses[1].arriv, "251020232300"); // 25th October 2023, 23:00
    for (int i = 0; i < MAX_SEATS; i++) buses[1].seats[i] = 1; // All seats available

    // Bus 3: Chennai to Madurai
    buses[2].num = 1003;
    strcpy(buses[2].source, "Chennai");
    strcpy(buses[2].dest, "Madurai");
    strcpy(buses[2].dep, "251020231600"); // 25th October 2023, 16:00
    strcpy(buses[2].arriv, "251020230100"); // 26th October 2023, 01:00
    for (int i = 0; i < MAX_SEATS; i++) buses[2].seats[i] = 1; // All seats available

    // Bus 4: Chennai to Trichy
    buses[3].num = 1004;
    strcpy(buses[3].source, "Chennai");
    strcpy(buses[3].dest, "Trichy");
    strcpy(buses[3].dep, "251020231700"); // 25th October 2023, 17:00
    strcpy(buses[3].arriv, "251020230300"); // 26th October 2023, 03:00
    for (int i = 0; i < MAX_SEATS; i++) buses[3].seats[i] = 1; // All seats available

    // Bus 5: Chennai to Pondicherry
    buses[4].num = 1005;
    strcpy(buses[4].source, "Chennai");
    strcpy(buses[4].dest, "Pondicherry");
    strcpy(buses[4].dep, "251020231800"); // 25th October 2023, 18:00
    strcpy(buses[4].arriv, "251020232200"); // 25th October 2023, 22:00
    for (int i = 0; i < MAX_SEATS; i++) buses[4].seats[i] = 1; // All seats available
}

