/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** parsing
*/
#include "my.h"
#include <string.h>

static int valeur_abs(int nb)
{
    if (nb < 0)
        return -nb;
    return nb;
}

int good_pos(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    int nb = give_ligne(filepath);
    int taille = 0;
    int n1 = 0;
    int n2 = 0;

    for (int o = 0; o < nb; ++o) {
        getline(&ligne, &longueur, fichier);
        taille = my_getnbr(ligne);
        n1 = my_getnbr_c(ligne[3]);
        n2 = my_getnbr_c(ligne[6]);
        if ((valeur_abs(ligne[2] - ligne[5]) + valeur_abs(n1 - n2)) + 1 !=
            valeur_abs(taille)) {
            return 84;
        }
    }
    fclose(fichier);
    return 0;
}

int diagonal(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    char *ligne = NULL;
    size_t longueur = 0;
    int nb = give_ligne(filepath);

    for (int o = 0; o < nb; ++o) {
        getline(&ligne, &longueur, fichier);
        if (ligne[2] != ligne[5] && ligne[3] != ligne[6])
            return 84;
        if (ligne[3] != ligne[6] && ligne[2] != ligne[5])
            return 84;
    }
    return 0;
}
