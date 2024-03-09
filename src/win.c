/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** player 1
*/
#include "my.h"

static int win_2(map_t1 *map_p1, int i, int j, int *x)
{
    if (map_p1->map_attack[i][j] == 'x') {
        *x = *x + 1;
    }
}

int win_or_not(map_t1 *map_p1)
{
    int x = 0;

    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 17; ++j) {
            win_2(map_p1, i, j, &x);
        }
    }
    if (x == 14) {
        game_data.win = 1;
        return 1;
    }
}

int display_win(map_t1 *map_p1)
{
    win_or_not(map_p1);
    if (game_data.win == 1) {
        mini_printf("my navy:\n");
        for (int i = 0; i < 10; ++i) {
            mini_printf("%s", map_p1->map_boat_mine[i]);
        }
        mini_printf("\nenemy navy:\n");
        for (int i = 0; i < 10; ++i) {
            mini_printf("%s", map_p1->map_attack[i]);
        }
        mini_printf("\nI won\n");
        game_data.loose = 1;
        return 1;
    }
    return 0;
}
