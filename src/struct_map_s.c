/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** struct map_s
*/
#include "my.h"

map_t1 *create_struct_map(char *filepath_mine)
{
    map_t1 *new;

    new = malloc(sizeof(map_t1));
    new->map_boat_mine = open_file(filepath_mine);
    new->map_attack = map_empty();
    return new;
}
