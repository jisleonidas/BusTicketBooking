#ifndef UTIL_H
#define UTIL_H

#include "header.h"

void display_menu();
void slice(char* result, char* str, size_t start, size_t end);
void parse_datetime(char string[], char result[]);
void display_datetime(char datetime[]);
void display_seats();
int count_free_seats(Bus* bus_ptr);
float calculate_fare(float base_fare, int count_c, int count_s);
void display_booking(Ticket* ticket_ptr);
void display_bookings();
int is_whitespace(char str[MAX_STR_LEN]);
void convert_lowercase(char str[MAX_STR_LEN]);
int compare_string(char a[MAX_STR_LEN], char b[MAX_STR_LEN]);
int usergetline(char buf[MAX_STR_LEN]);
void skipgarb();
void cleanup(int signal);
void print_header(char *header);

#endif
