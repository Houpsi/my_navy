/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** reproduire un mini printf
*/
#include "my.h"

int cond3(int i, const char *format, va_list list)
{
    if (format[i + 1] == '%')
        my_putchar(37);
    else if (format[i + 1] == 'l')
        my_put_nbr_uns(va_arg(list, int));
}

int cond2(int i, const char *format, va_list list)
{
    if (format[i + 1] == 's')
        my_putstr(va_arg(list, char *));
    else if (format[i + 1] == 'c')
        my_putchar(va_arg(list, int));
}

int cond(int i, const char *format, va_list list)
{
    if (format[i + 1] == 'd')
        my_put_nbr(va_arg(list, int));
    else if (format[i + 1] == 'i')
        my_put_nbr(va_arg(list, int));
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int count = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            cond(i, format, list);
            cond2(i, format, list);
            cond3(i, format, list);
            i += 2;
        } else {
            my_putchar(format[i]);
            i++;
        }
    }
    va_end(list);
}
