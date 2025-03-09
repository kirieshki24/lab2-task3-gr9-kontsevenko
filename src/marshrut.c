#include <stdio.h>
#include <string.h>
#include "marshrut.h"

// Функция для создания массива маршрутов
void create_routes(MARSHRUT1 routes[], int *count) {
    printf("Введите количество маршрутов (не более %d): ", MAX_ROUTES);
    scanf("%d", count);
    
    if (*count > MAX_ROUTES) {
        printf("Ошибка: Максимальное количество маршрутов - %d\n", 
MAX_ROUTES);
        *count = MAX_ROUTES;
    }

    for (int i = 0; i < *count; i++) {
        printf("Введите данные для маршрута %d\n", i + 1);
        printf("Номер маршрута: ");
        scanf("%d", &routes[i].number);
        printf("Начальный пункт: ");
        scanf("%s", routes[i].start_point);
        printf("Конечный пункт: ");
        scanf("%s", routes[i].end_point);
        printf("Длина маршрута: ");
        scanf("%lf", &routes[i].length);
    }
}

// Функция для нахождения маршрута с минимальной длиной
MARSHRUT1 find_min_length_route(const MARSHRUT1 routes[], int count) {
    MARSHRUT1 min_route = routes[0];
    for (int i = 1; i < count; i++) {
        if (routes[i].length < min_route.length) {
            min_route = routes[i];
        }
    }
    return min_route;
}

// Функция сортировки маршрутов по длине (пузырьковая сортировка)
void sort_routes_by_length(MARSHRUT1 routes[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (routes[j].length > routes[j + 1].length) {
                MARSHRUT1 temp = routes[j];
                routes[j] = routes[j + 1];
                routes[j + 1] = temp;
            }
        }
    }
}

// Функция вывода маршрутов по указанному пункту
void print_routes_by_point(const MARSHRUT1 routes[], int count, const char 
*point) {
    printf("Маршруты, содержащие пункт \"%s\":\n", point);
    for (int i = 0; i < count; i++) {
        if (strcmp(routes[i].start_point, point) == 0 || 
strcmp(routes[i].end_point, point) == 0) {
            printf("%d: %s -> %s (%.2lf км)\n", 
                   routes[i].number, routes[i].start_point, 
routes[i].end_point, routes[i].length);
        }
    }
}

// Функция вывода всех маршрутов
void print_routes(const MARSHRUT1 routes[], int count) {
    printf("\nСписок маршрутов:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s -> %s (%.2lf км)\n", 
               routes[i].number, routes[i].start_point, 
routes[i].end_point, routes[i].length);
    }
}
