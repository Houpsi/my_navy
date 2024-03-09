/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** main function
*/
#include "my.h"

int my_help()
{
    mini_printf("USAGE\n");
    mini_printf("\t./my_navy [first_player_pid] navy_positions\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("\tfirst_player_pid: only for the 2nd player");
    mini_printf(" pid of the first player.\n");
    mini_printf("\tnavy_positions: file representing");
    mini_printf("the positions of the ships.\n");
    return 0;
}
