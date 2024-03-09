/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** parsing
*/
#include "my.h"
#include <string.h>

int ligne_1(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    int nb = give_ligne(filepath);

    for (int o = 0; o < nb; o++) {
        getline(&ligne, &longueur, fichier);
        if (ligne[0] > '5')
            return 84;
        if (ligne[0] <= '1')
            return 84;
    }
    return 0;
}

int verify_file(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    int nb = give_ligne(filepath);

    if (same(filepath) == 1)
        return 84;
    for (int o = 0; o < nb; o++) {
        getline(&ligne, &longueur, fichier);
        if (ligne[2] < 65 || ligne[2] > 72 || ligne[5] < 65 || ligne[5] > 72)
            return 84;
        if (ligne[1] != 58 || ligne[4] != 58)
            return 84;
        if (ligne[3] <= '0' || ligne[3] > '8' || ligne[6] <= '0' || ligne[6]
        > '8')
            return 84;
    }
    fclose(fichier);
    return 0;
}

static int aide(char **map, int i, int j, int *nb)
{
    if (map[i][j] >= '2' && map[i][j] <= '5') {
        *nb += 1;
    }
}

static void cond_if(const char *ligne, int *deux, int *trois)
{
    if (ligne[0] == '2')
        *deux = *deux - 1;
    if (ligne[0] == '3')
        *trois = *trois - 1;
}

int same(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    int deux = 1;
    int trois = 1;
    int quatre = 1;
    int cinq = 1;
    int nb = give_ligne(filepath);

    for (int o = 0; o < nb; ++o) {
        getline(&ligne, &longueur, fichier);
        cond_if(ligne, &deux, &trois);
        if (ligne[0] == '4')
            quatre -= 1;
        if (ligne[0] == '5')
            cinq -= 1;
    }
    if (deux != 0 || trois != 0 || quatre != 0 || cinq != 0)
        return 1;
    return 0;
}

int superpose(char *filepath)
{
    char **map = open_file(filepath);
    int nb = 0;

    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 17; ++j) {
            aide(map, i, j, &nb);
        }
    }
    if (nb != 14) {
        return 1;
    }
    free(map);
    return 0;
}

static int can_open_file(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");

    if (fichier == NULL)
        return 84;
    fclose(fichier);
    return 0;
}

static int nb_ligne(char *filepath)
{
    int nb = give_ligne(filepath);

    if (nb != 4)
        return 1;
    return 0;
}

static int nb_charactere(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    int nb = 4;
    int size = 0;

    for (int o = 0; o < nb; o++) {
        getline(&ligne, &longueur, fichier);
        size = my_strlen(ligne);
        if (o == 3 && size != 7)
            return 84;
        if (size != 8 && o != 3)
            return 84;
    }
    fclose(fichier);
    return 0;
}

int error_handling(char *filepath)
{
    if (can_open_file(filepath) == 84 || nb_ligne(filepath) == 1 ||
    ligne_1(filepath) == 84 || verify_file(filepath) == 84 ||
    nb_charactere(filepath) == 84 || superpose(filepath) == 1
    || same(filepath) == 1 || diagonal(filepath) == 84)
        return 1;
    return 0;
}
