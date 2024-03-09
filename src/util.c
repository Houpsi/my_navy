/*
** EPITECH PROJECT, 2023
** util
** File description:
** fonction
*/
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    char h = 0;

    while (str[h] != '\0') {
        my_putchar(str[h]);
        h++;
    }
}

int my_put_nbr(int nb)
{
    int h = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}

int my_put_nbr_uns(int nb)
{
    int c = 0;

    if (nb < 0) {
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr_uns(nb / 10);
        c ++;
    }
    my_putchar(nb % 10 + 48);
    return c + 1;
}

int my_strlen(char const *str)
{
    char h = 0;

    if (str == NULL)
        return 0;
    while (str[h] != '\0') {
        h ++;
    }
    return h;
}
