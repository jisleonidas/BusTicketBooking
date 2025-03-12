#ifndef UTIL_H
#define UTIL_H

#include "header.h"

void display_menu();
void slice(char* result, char* str, size_t start, size_t end);
void parse_datetime(char string[], char result[]);
void display_datetime(char datetime[]);
void display_seats();
int count_free_seats(Bus* bus_ptr);
int usergetline(char buf[MAX_STR_LEN]);
void skipgarb();

#endif
