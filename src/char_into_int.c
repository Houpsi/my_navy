/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** transform char into int
*/
#include "my.h"

int string_to_int(const char *str)
{
    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        ++str;
    }
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9')
            result = result * 10 + (*str - '0');
        ++str;
    }
    return result * sign;
}
