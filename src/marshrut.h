#ifndef MARSHRUT_H
#define MARSHRUT_H

#define MAX_ROUTES 10
#define MAX_NAME_LEN 50

typedef struct {
    int number;s
    char start_point[MAX_NAME_LEN];
    char end_point[MAX_NAME_LEN];
    double length;
} MARSHRUT1;

void create_routes(MARSHRUT1 routes[], int *count);
MARSHRUT1 find_min_length_route(const MARSHRUT1 routes[], int count);
void sort_routes_by_length(MARSHRUT1 routes[], int count);
void print_routes_by_point(const MARSHRUT1 routes[], int count, const char *point);
void print_routes(const MARSHRUT1 routes[], int count);

#endif
