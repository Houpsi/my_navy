/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** main function
*/
#include "my.h"

int main(int argc, char **argv)
{
    game_data_t *lol = malloc(sizeof(game_data_t));

    if (argc < 2 || argc > 3)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0)
        my_help();
    if (argc == 2) {
        if (error_handling(argv[1]) == 1)
            return 84;
        game_data.filepath_1 = argv[1];
        return player1(argc, argv);
    }
    if (argc == 3) {
        if (error_handling(argv[2]) == 1)
            return 84;
        game_data.filepath_2 = argv[2];
        return player2(argc, argv);
    }
    free(lol);
    return 0;
}
