/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** find the number
*/


int condition(int h, int no_nombre, char const *str)
{
    if (str[h + 1] < 48 || str[h + 1] > 57)
        no_nombre = 1;
    return no_nombre;
}

int my_getnbr(char const *str)
{
    int h = 0;
    int nb = 0;
    int devant = 1;
    int no_nombre = 0;

    while (str[h] != '\0' && no_nombre == 0) {
        if (str[h] >= 48 && str[h] <= 57) {
            nb = nb * 10 + (str[h] - 48);
            no_nombre = condition(h, no_nombre, str);
            }
        if (str[h - 1] == 45)
            devant = devant * -1;
        h++;
        if (nb > 32767 || nb < -32767)
            return 0;
    }
    return (nb * devant);
}

int my_getnbr_c(char const str)
{
    if (str == '1')
        return 1;
    if (str == '2')
        return 2;
    if (str == '3')
        return 3;
    if (str == '4')
        return 4;
    if (str == '5')
        return 5;
    if (str == '6')
        return 6;
    if (str == '7')
        return 7;
    if (str == '8')
        return 8;
    if (str == '9')
        return 9;
}
