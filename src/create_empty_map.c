/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** parsing
*/
#include "my.h"

char **mem_alloc_2d_array(void)
{
    char **tableau;

    tableau = malloc((9 + 1) * sizeof(char *));
    tableau[9] = NULL;
    for (int i = 0; i < 10; i++) {
        tableau[i] = malloc((18 + 1) * sizeof(char));
        tableau[i][18] = '\0';
        tableau[i][17] = '\n';
    }
    return tableau;
}

char **put_letter_num(char **map)
{
    int in = 0;

    for (int w = 2; w < 17; ++w) {
        if (map[0][w] == '.') {
            map[0][w] = 65 + in;
            in++;
        }
    }
    in = 0;
    for (int w = 2; w < 10; ++w) {
        map[w][0] = 49 + in;
        in++;
    }
    return map;
}

char **put_line(char **map)
{
    for (int a = 0; a < 17; a++) {
        map[1][a] = '-';
    }
    for (int v = 0; v < 10; ++v) {
        map[v][1] = '|';
    }
    map[0][0] = ' ';
    map[1][1] = '+';
    return map;
}

char **cond_space_map(char **map, int *space, int *i, int *j)
{
    if (*space == 0) {
        map[*i][*j] = '.';
        *space = 1;
    } else {
        map[*i][*j] = ' ';
        *space = 0;
    }
}

char **map_empty(void)
{
    char **map = mem_alloc_2d_array();
    int space = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 17; ++j) {
            cond_space_map(map, &space, &i, &j);
        }
        space = 0;
    }
    put_line(map);
    put_letter_num(map);
    return map;
}
