#ifndef UTIL_H
#define UTIL_H

#include "header.h"
void menu();

void slice(char* result, char* str, size_t start, size_t end);
void parse_datetime(char string[], char result[]);
void display_datetime(char datetime[]);
void display_seats();

#endif
