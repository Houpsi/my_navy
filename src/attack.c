/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** attack
*/
#include "my.h"

int attack(char letter, int line, map_t1 *maps_p1)
{
    int j = which_colums(letter);
    int i = line + 1;

    if (maps_p1->map_boat_mine[i][j] == '.') {
        maps_p1->map_boat_mine[i][j] = 'o';
        game_data.hit = 0;
        game_data.missed = 1;
        return 0;
    } else if ((maps_p1->map_boat_mine[i][j] < '6' &&
        maps_p1->map_boat_mine[i][j] > '0') || maps_p1->map_boat_mine[i][j] ==
        'x') {
        maps_p1->map_boat_mine[i][j] = 'x';
        game_data.hit = 1;
    } else {
        game_data.missed = 1;
    }
}

int attack_v2(char letter, int line, map_t1 *maps_p1)
{
    int j = which_colums(letter);
    int i = line + 1 - '0';

    maps_p1->map_attack[i][j] = 'o';
}

int attack_v3(char letter, int line, map_t1 *maps_p1)
{
    int j = which_colums(letter);
    int i = line + 1 - '0';

    maps_p1->map_boat_mine[i][j] = 'x';
}

int attack_v4(char letter, int line, map_t1 *maps_p1)
{
    int j = which_colums(letter);
    int i = line + 1 - '0';

    maps_p1->map_attack[i][j] = 'x';
}
