/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** player 1
*/
#include "my.h"

static int loose_2(map_t1 *map, int i, int j, int *x)
{
    if (map->map_boat_mine[i][j] == 'x') {
        *x = *x + 1;
    }
}

int loose_or_not(map_t1 *map)
{
    int x = 0;

    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 17; ++j) {
            loose_2(map, i, j, &x);
        }
    }
    if (x == 14) {
        game_data.loose = 1;
        return 1;
    }
}

int display_loose(map_t1 *map_p1)
{
    loose_or_not(map_p1);
    if (game_data.loose == 1) {
        mini_printf("my navy:\n");
        for (int i = 0; i < 10; ++i) {
            mini_printf("%s", map_p1->map_boat_mine[i]);
        }
        mini_printf("\nenemy navy:\n");
        for (int i = 0; i < 10; ++i) {
            mini_printf("%s", map_p1->map_attack[i]);
        }
        mini_printf("\nEnemy won\n");
        return 1;
    }
    return 0;
}
