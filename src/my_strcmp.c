/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** compare les deux chaînes s1 et s2
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int ii = 0;
    int result = 0;

    while (s1[i] != '\0' && s2[ii] != '\0') {
        if (s1[i] != s2[ii]) {
            result = (s1[i] - s2[ii]);
            return (result);
        }
        i = i + 1;
        ii = ii + 1;
    }
}
