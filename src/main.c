#include <stdio.h>
#include "marshrut.h"

int main() {
    MARSHRUT1 routes[MAX_ROUTES];
    int count = 0;
    
    create_routes(routes, &count);

    printf("\nМаршрут с минимальной длиной:\n");
    MARSHRUT1 min_route = find_min_length_route(routes, count);
    printf("%d: %s -> %s (%.2lf км)\n", 
           min_route.number, min_route.start_point, min_route.end_point, min_route.length);
    
    printf("\nСортировка маршрутов по длине...\n");
    sort_routes_by_length(routes, count);
    print_routes(routes, count);
    
    char point[MAX_NAME_LEN];
    printf("\nВведите название пункта для поиска маршрутов: ");
    scanf("%s", point);
    print_routes_by_point(routes, count, point);
    
    return 0;
}
