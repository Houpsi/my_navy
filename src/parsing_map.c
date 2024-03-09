/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** parsing
*/
#include "my.h"
#include <string.h>

int give_ligne(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    int nb = 0;

    while (getline(&ligne, &longueur, fichier) != -1) {
        nb += 1;
    }
    fclose(fichier);
    return nb;
}

int which_colums(char letter)
{
    if (letter == 'A')
        return 2;
    if (letter == 'B')
        return 4;
    if (letter == 'C')
        return 6;
    if (letter == 'D')
        return 8;
    if (letter == 'E')
        return 10;
    if (letter == 'F')
        return 12;
    if (letter == 'G')
        return 14;
    if (letter == 'H')
        return 16;
}

int which_line(char letter)
{
    if (letter == '1')
        return 2;
    if (letter == '2')
        return 3;
    if (letter == '3')
        return 4;
    if (letter == '4')
        return 5;
    if (letter == '5')
        return 6;
    if (letter == '6')
        return 7;
    if (letter == '7')
        return 8;
    if (letter == '8')
        return 9;
}

char **add_boat(char *ligne, char **map)
{
    int len_boat = ligne[0] - '0';
    int start = ligne[3] - '0';
    int tmp;

    if (ligne[2] == ligne[5]) {
        tmp = which_colums(ligne[2]);
        for (int i = 0; i < len_boat; ++i) {
            map[start +(i + 1)][tmp] = len_boat + '0';
        }
    }
    if (ligne[2] != ligne[5]) {
        tmp = which_line(ligne[3]);
        for (int i = 0; i < (len_boat * 2); i += 2) {
            map[tmp][which_colums(ligne[2]) + i] = len_boat + '0';
        }
    }
    return map;
}

char **open_file(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    char **map = map_empty();
    int nb = give_ligne(filepath);

    for (int o = 0; o <= nb; o++) {
        getline(&ligne, &longueur, fichier);
        add_boat(ligne, map);
    }
    return map;
}
