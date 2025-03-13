#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_STR_LEN 30
#define MAX_SEATS 40

#define MAX_BUSES 5
#define MAX_PASSENGERS 20
#define MAX_TICKETS 20

#define TRUE 1
#define FALSE 0

struct bus_t {
    int num; // Bus number
    char source[MAX_STR_LEN], dest[MAX_STR_LEN];  // Source and destination.
    char dep[13], arriv[13];  // Departure and arrival time in DDMMYYYYHHMM format.
    int seats[MAX_SEATS];  // Boolean array of seats with availability status.
    float base_fare;  // Base fare for bus route.
} typedef Bus;

struct passenger_t {
    char name[MAX_STR_LEN];  // Name of passenger.
    int age; // Age of passenger.
    char pref;  // Seat preference type: c (chair/sitting), s (sleeper)
} typedef Passenger;

struct ticket_t {
    int bus_num, booking_num, passengers_num;
    Passenger* passengers;  // List of passengers.
    int* seats;  // List of seats booked for passengers.
    float total_fare;
} typedef Ticket;

extern Bus BUSES[MAX_BUSES];
extern Passenger PASSENGERS[MAX_PASSENGERS];
extern Ticket TICKETS[MAX_TICKETS];

extern int TICKETS_BOOKED;

#endif
